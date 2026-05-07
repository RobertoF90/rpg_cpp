#include "dungeon.h"
#include <cstdlib>
#include <algorithm>

void Dungeon::displayMap()
{
    std::cout << "\n=== MAP ===\n";
    for (int y = 0; y < dungeonGrid.size(); y++)
    {
        for (int x = 0; x < dungeonGrid[y].size(); x++)
        {
            if (x == player->tileX && y == player->tileY)
            {
                std::cout << " P ";
            }
            else
            {
                switch (dungeonGrid[y][x].type)
                {
                case TILE_WALL:
                    std::cout << " # ";
                    break;
                case TILE_WATER:
                    std::cout << " ~ ";
                    break;
                case TILE_ITEM:
                    std::cout << " $ ";
                    break;
                case TILE_ENEMY:
                    std::cout << " E ";
                    break;
                default:
                    std::cout << " . ";
                    break;
                }
            }
        }
        std::cout << "\n";
    }
}

bool Dungeon::isWalkable(int tileX, int tileY)
{
    if (tileX < 0 || tileX >= dungeonGrid[0].size() || tileY < 0 || tileY >= dungeonGrid.size())
    {
        return false;
    }
    Tile &tile = dungeonGrid[tileY][tileX];
    if (tile.type == TILE_WALL || tile.type == TILE_WATER)
        return false;
    if (tile.type == TILE_ITEM)
        return !tile.itemCollected;
    return true;
}
bool Dungeon::movePlayer(char direction)
{
    int newX = player->tileX;
    int newY = player->tileY;

    switch (direction)
    {
    case 'N':
    case 'n':
        newY--;
        break;
    case 'S':
    case 's':
        newY++;
        break;
    case 'W':
    case 'w':
        newX--;
        break;
    case 'E':
    case 'e':
        newX++;
        break;
    }

    if (isWalkable(newX, newY))
    {
        player->tileX = newX;
        player->tileY = newY;

        if (dungeonGrid[newY][newX].type == TILE_ITEM)
        {
            std::cout << "You found an item!\n";
            dungeonGrid[newY][newX].type = TILE_EMPTY;
            dungeonGrid[newY][newX].itemCollected = true;
        }
        return true;
    }
    else
    {
        std::cout << "Can't move there!\n";
        return false;
    }
}

void Dungeon::loadFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error: Could not open " << filename << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    int maxWidth = 0;

    while (std::getline(file, line))
    {

        // Trim CRLF if needed
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        lines.push_back(line);
        if (line.length() > maxWidth)
            maxWidth = line.length();
    }

    file.close();

    int height = lines.size();
    int width = maxWidth;

    // Resize grid
    dungeonGrid.resize(height);
    for (int y = 0; y < height; y++)
    {
        dungeonGrid[y].resize(width);
        for (int x = 0; x < width; x++)
        {
            char c = (x < lines[y].length()) ? lines[y][x] : '1';
            dungeonGrid[y][x].type = c - '0';
            dungeonGrid[y][x].isWalkable = (dungeonGrid[y][x].type == TILE_EMPTY || dungeonGrid[y][x].type == TILE_ITEM);
            dungeonGrid[y][x].isExplored = false;
            dungeonGrid[y][x].itemCollected = false;
        }
    }
}

int Dungeon::manhattanDist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

bool Dungeon::isNodeWalkable(Dungeon *dungeon, int x, int y)
{
    if (x < 0 || x >= dungeon->dungeonGrid[0].size() || y < 0 || y >= dungeon->dungeonGrid.size())
        return false;

    Tile &tile = dungeon->dungeonGrid[y][x];
    return (tile.type == TILE_EMPTY || tile.type == TILE_ITEM) && !tile.itemCollected;
}

std::vector<Node *> Dungeon::findPath(int startX, int startY, int goalX, int goalY)
{
    // Open list: nodes to be evaluated, sorted by f-cost (lowest first)
    std::vector<Node *> openList;
    // Closed list: nodes already evaluated (use 2D bool array matching grid)
    std::vector<std::vector<bool>> closedList(dungeonGrid.size(), std::vector<bool>(dungeonGrid[0].size(), false));

    // Create start node
    Node *startNode = new Node(startX, startY);
    startNode->hCost = manhattanDist(startX, startY, goalX, goalY);
    openList.push_back(startNode);

    // Store all allocated nodes for cleanup
    std::vector<Node *> allNodes;
    allNodes.push_back(startNode);

    while (!openList.empty())
    {
        // Find node with lowest f-cost in open list
        Node *current = openList[0];
        int currentIndex = 0;
        for (int i = 1; i < openList.size(); i++)
        {
            if (openList[i]->fCost() < current->fCost())
            {
                current = openList[i];
                currentIndex = i;
            }
        }

        // Remove current from open list and add to closed list
        openList.erase(openList.begin() + currentIndex);
        closedList[current->y][current->x] = true;

        // Check if goal reached
        if (current->x == goalX && current->y == goalY)
        {
            // Reconstruct path (from goal to start, then reverse)
            std::vector<Node *> path;
            Node *temp = current;
            while (temp != nullptr)
            {
                path.insert(path.begin(), temp);
                temp = temp->parent;
            }
            // Clean up nodes in path
            for (Node *n : allNodes)
            {
                if (std::find(path.begin(), path.end(), n) == path.end())
                {
                    delete n;
                }
            }
            return path;
        }

        // Check neighbors (N, S, E, W)
        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};

        for (int i = 0; i < 4; i++)
        {
            int newX = current->x + dx[i];
            int newY = current->y + dy[i];

            // Skip if not walkable or already closed
            if (!isNodeWalkable(this, newX, newY) || closedList[newY][newX])
            {
                continue;
            }

            int newG = current->gCost + 1; // Each step costs 1

            // Check if this path neighbor is better
            bool inOpenList = false;
            for (Node *n : openList)
            {
                if (n->x == newX && n->y == newY)
                {
                    inOpenList = true;
                    if (newG < n->gCost)
                    {
                        n->gCost = newG;
                        n->parent = current;
                    }
                    break;
                }
            }

            // Add to open list if not already there
            if (!inOpenList)
            {
                Node *neighbor = new Node(newX, newY);
                neighbor->gCost = newG;
                neighbor->hCost = manhattanDist(newX, newY, goalX, goalY);
                neighbor->parent = current;
                openList.push_back(neighbor);
                allNodes.push_back(neighbor);
            }
        }
    }

    // No path found - clean up and return empty
    for (Node *n : allNodes)
    {
        delete n;
    }
    return {};
}