#ifndef WARRIOR_H
#define WARRIOR_H

#include "player.h"

class Warrior : public Player
{

public:
    Warrior() : Player() {
                };

    void initializeClass();
    void viewSkills();
};

#endif
