#ifndef DUNGEON_H
#define DUNGEON_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "player.h"

class Dungeon;

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

struct Trigger
{
    bool triggered;
    bool repeatable;

    Trigger() : triggered(false), repeatable(true) {};
    virtual ~Trigger() = default;

    virtual void onEnter(Dungeon *dungeon) {}
    virtual void onStay(Dungeon *dungeon) {}
    virtual void onExit(Dungeon *dungeon) {}
};

struct MessageTrigger : public Trigger
{
    std::string message;

    MessageTrigger(const std::string &msg) : message(msg) {}

    void onEnter(Dungeon *dungeon) override
    {
        std::cout << message << "\n";
        if (!repeatable)
        {
            triggered = true;
        }
    }
};

struct Zone
{
    int x1, y1, x2, y2; // Rectangle bounds (inclusive)
    std::vector<Trigger *> triggers;

    // Check if point (x,y) is inside this zone
    bool contains(int x, int y) const
    {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;
    }

    // Check and fire triggers for current player position
    void checkTriggers(int playerX, int playerY, Dungeon *dungeon, bool wasInZone)
    {
        bool isInZone = contains(playerX, playerY);

        if (isInZone && !wasInZone)
        {
            // Just entered
            for (Trigger *t : triggers)
            {
                if (!t->triggered || t->repeatable)
                {
                    t->onEnter(dungeon);
                }
            }
        }
        else if (isInZone && wasInZone)
        {
            // STaying in zone
            for (Trigger *t : triggers)
            {
                if (t->repeatable)
                {
                    t->onStay(dungeon);
                }
            }
        }
        else if (!isInZone && wasInZone)
        {
            // Just exited
            for (Trigger *t : triggers)
            {
                t->onExit(dungeon);
            }
        }
    }
};

class Dungeon
{
    Player *player;

private:
    std::vector<Zone> zones;
    std::vector<bool> zoneStatus;

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
        initZones();
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
    void initZones();
};

#endif