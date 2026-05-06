
#include "dungeon.h"

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