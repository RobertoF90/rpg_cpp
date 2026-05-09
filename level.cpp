#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "level.h"

#include <fstream>
#include <sstream>

#include <algorithm>
#include <cctype>

// SKILLS
static std::string trim(const std::string &str)
{
    size_t first = 0;
    while (first < str.size() && std::isspace(static_cast<unsigned char>(str[first])))
        first++;
    size_t last = str.size();
    while (last > first && std::isspace(static_cast<unsigned char>(str[last - 1])))
        last--;
    return str.substr(first, last - first);
}

void Level::loadLevel(const std::string &filename, std::vector<std::string> &rooms, std::vector<std::string> &enemies, std::vector<int> &enemyHPs)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Failed to load level!" << std::endl;
        return;
    }

    std::string line;
    std::string section = "";

    while (std::getline(file, line))
    {
        line = trim(line);
        if (line == "===ROOMS===")
        {
            section = "rooms";
            continue;
        }
        else if (line == "===ENEMIES===")
        {
            section = "enemies";
            continue;
        }
        else if (line == "===END===")
        {
            break;
        }

        if (section == "rooms")
        {
            rooms.push_back(line);
        }
        else if (section == "enemies")
        {
            // Parse: "Rat,10,1"
            std::stringstream ss(line);
            std::string name, hp, weakness;
            std::getline(ss, name, ',');
            std::getline(ss, hp, ',');
            std::getline(ss, weakness, ',');

            enemies.push_back(name);
            enemyHPs.push_back(std::stoi(hp)); // converts string into integer
        }
    }

    file.close();
    std::cout << "Level loaded: " << rooms.size() << " rooms, " << enemies.size() << " enemy types" << std::endl;
}
