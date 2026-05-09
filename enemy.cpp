#include <iostream>
#include "enemy.h"

void Enemy::takeDamage(float damage)
{
    Character::takeDamage(damage); // Call the base class method first to reduce HP

    if (getHp() <= 0)
    {
        std::cout << name << " has been defeated!" << std::endl;
        std::cout << "You earn " << xpReward << " xp" << std::endl;
    }
    else
    {
        std::cout << name << " takes " << damage << " damage!" << std::endl;

        Character::viewBattleStats(); // Show updated HP after taking damage
    }
}

void Enemy::attack(Character &target)
{
    Character::attack(target);
    std::cout << "smack!" << std::endl;

    float damage = getStrength() - target.getDefense();
    if (damage < 1)
    {
        damage = 1; // Ensure minimum damage of 1
    }

    target.takeDamage(damage);
}