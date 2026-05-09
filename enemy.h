#ifndef ENEMY_H
#define ENEMY_H

#include <string>
#include "character.h"

class Enemy : public Character
{
public:
    Enemy(
        std::string weakTo = "Sword",
        int xpReward = 5)
        : Character()
    {
        this->weakTo = weakTo;
        this->xpReward = xpReward;
    };

    std::string weakTo;
    int xpReward;

    void attack(Character &target) override;

    void takeDamage(float damage) override;
};

#endif
