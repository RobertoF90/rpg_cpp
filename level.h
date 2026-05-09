#ifndef LEVEL_H
#define LEVEL_H

#include "player.h"

class Level
{

public:
    void loadLevel(const std::string &filename, std::vector<std::string> &rooms, std::vector<std::string> &enemies, std::vector<int> &enemyHPs);
};

#endif
