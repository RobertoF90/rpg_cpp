
#include "data.h"
#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

void Data::saveGame(Player *player)
{
    std::ofstream save("save.json");
    if (!save.is_open())
    {
        std::cout << "Error: Could not open save file." << std::endl;
        return;
    }

    json saveData;
    saveData["name"] = player->name;
    saveData["level"] = player->level;
    saveData["xpNeeded"] = player->xpNeeded;
    saveData["hp"] = player->getHp();
    saveData["mp"] = player->getMp();

    // save inventory

    json playerInventory = json::array();
    auto &inventoryItems = player->inventory.getItems();
    for (const auto &pair : inventoryItems)
    {
        json item;
        item["name"] = pair.first;
        item["quantity"] = pair.second;
        playerInventory.push_back(item);
    }
    saveData["inventory"] = playerInventory;

    // save defeated enemies

    json defeated = json::array();
    for (const auto &enemy : player->defeatedEnemies)
    {
        defeated.push_back(enemy);
    }
    saveData["defeatedEnemies"] = defeated;

    save << saveData.dump(4) << std::endl;
    save.close();
    std::cout << "Game saved successfully!" << std::endl;
}

void Data::loadGame(Player *player)
{
    std::ifstream load("save.json");
    if (!load.is_open())
    {
        std::cout << "Error: Could not open save file." << std::endl;
        return;
    }

    json loadData;
    load >> loadData;

    player->name = loadData["name"];
    player->level = loadData["level"];
    player->xpNeeded = loadData["xpNeeded"];
    player->setHp(loadData["hp"]);
    player->setMp(loadData["mp"]);

    // load inventory

    auto &items = player->inventory.getItems();
    items.clear();
    for (const auto &item : loadData["inventory"])
    {
        items[item["name"]] = item["quantity"];
    }

    // load defeated enemies

    player->defeatedEnemies.clear();
    for (const auto &enemy : loadData["defeatedEnemies"])
    {
        player->defeatedEnemies.insert(enemy);
    }
    load.close();
    std::cout << "Game loaded successfully!" << std::endl;
}