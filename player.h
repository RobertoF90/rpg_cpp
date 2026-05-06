#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <map>
#include <set>
#include "character.h"
#include "enemy.h"
#include "inventory.h"
#include "weapon.h"

class Player : public Character
{

public:
    Inventory inventory;
    Weapon weapon;
    Player(
        int xpNeeded = 100) : Character()
    {
        this->xpNeeded = xpNeeded;
        weaponDamage["Sword"] = 3.0f;
    };

    std::map<std::string, float> weaponDamage;

    std::set<std::string> defeatedEnemies;

    int xpNeeded;

    void setName();

    void checkHp();
    void viewCharacter();

    void attack(Character &target) override;

    void takeDamage(float damage) override;

    // bool movePlayer(char direction);
};

#endif
