#ifndef SAVE_H
#define SAVE_H

#include "player.h"

namespace Data
{
    void saveGame(Player *player);
    void loadGame(Player *player);
}

#endif