#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "player.h"

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
};

#endif