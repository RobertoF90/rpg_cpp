#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <fstream>
#include "player.h"

void saveGame(Player *player)
{
    std::ofstream save("save.txt");
    if (!save.is_open())
    {
        std::cout << "Error: Could not open save file." << std::endl;
        return;
    }

    save << player->name << std::endl;
    save << player->level << std::endl;
    save << player->xpNeeded << std::endl;
    save << player->getHp() << std::endl;
    save << player->getMp() << std::endl;

    auto &inventoryItems = player->inventory.getItems();
    save << inventoryItems.size() << std::endl;
    for (const auto &pair : inventoryItems)
    {
        save << pair.first << std::endl;
        save << pair.second << std::endl;
    }

    save << player->defeatedEnemies.size() << std::endl;
    for (const auto &enemyName : player->defeatedEnemies)
    {
        save << enemyName << std::endl;
    }

    save.close();
    std::cout << "Game saved successfully!" << std::endl;
}

void loadGame(Player *player)
{
    std::ifstream load("save.txt");
    if (!load.is_open())
    {
        std::cout << "Error: Could not open save file." << std::endl;
        return;
    }

    std::getline(load, player->name);
    load >> player->level;
    load >> player->xpNeeded;
    int hp, mp;
    load >> hp >> mp;
    player->setHp(hp);
    player->setMp(mp);
    load.ignore();

    size_t inventorySize;
    load >> inventorySize;
    load.ignore();
    auto &inventoryItems = player->inventory.getItems();
    inventoryItems.clear();
    for (size_t i = 0; i < inventorySize; i++)
    {
        std::string itemName;
        int quantity;
        std::getline(load, itemName);
        load >> quantity;
        load.ignore();
        inventoryItems[itemName] = quantity;
    }

    size_t defeatedSize;
    load >> defeatedSize;
    load.ignore();
    player->defeatedEnemies.clear();
    for (size_t i = 0; i < defeatedSize; i++)
    {
        std::string enemyName;
        std::getline(load, enemyName);
        player->defeatedEnemies.insert(enemyName);
    }

    load.close();
    std::cout << "Game loaded successfully!" << std::endl;
}

#endif
