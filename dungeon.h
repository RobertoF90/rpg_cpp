#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "player.h"

struct Node
{
    int x, y;
    int gCost;    // Distance from start node;
    int hCost;    // Heuristic distance to goal
    Node *parent; // Parent node for path reconstruction

    Node(int x, int y) : x(x), y(y), gCost(0), hCost(0), parent(nullptr) {}

    int fCost() const
    {
        return gCost + hCost;
    }
};

class Dungeon
{
    Player *player;

public:
    struct Tile
    {
        int type;
        bool isWalkable;
        bool isExplored;
        bool itemCollected;
        std::string enemyName;
    };

    Dungeon(
        Player *p) : player(p)
    {
        loadFromFile("map1.txt");
    }
    enum TileType
    {
        TILE_EMPTY = 0,
        TILE_WALL = 1,
        TILE_WATER = 2,
        TILE_ITEM = 3,
        TILE_ENEMY = 4
    };

    std::vector<std::vector<Tile>> dungeonGrid;

    void displayMap();
    bool isWalkable(int tileX, int tileY);
    bool movePlayer(char direction);

    void loadFromFile(const std::string &filename);

    static int manhattanDist(int x1, int y1, int x2, int y2);

    std::vector<Node *> findPath(int startX, int startY, int goalX, int goalY);
    static bool isNodeWalkable(Dungeon *dungeon, int x, int y);
};

#endif