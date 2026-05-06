#include <iostream>
#include "character.h"

bool Character::isAlive() const
{
    return hp > 0;
}

void Character::viewBattleStats()
{
    std::cout << name << " " << hp << " / " << maxHp << "." << std::endl;
}

void Character::takeDamage(float damage)
{
    hp = hp - damage;
    if (hp < 0)
        hp = 0;
}

void Character::healDamage(int heal)
{
    hp = hp + heal;
    if (hp > maxHp)
        hp = maxHp;

    std::cout << "HP restored! " << hp << " / " << maxHp << std::endl;
}

int Character::getHp()
{
    return hp;
}

int Character::getMaxHp()
{
    return maxHp;
}

void Character::setHp(int h)
{
    if (h >= 0 && h <= maxHp)
    {
        hp = h;
    }
}

void Character::setMaxHp(int m)
{
    if (m >= 0)
    {
        maxHp = m;
    }
}

int Character::getMp()
{
    return mp;
}

int Character::getMaxMp()
{
    return maxMp;
}

void Character::setMaxMp(int m)
{
    if (m >= 0)
    {
        maxMp = m;
    }
}

void Character::setMp(int m)
{
    if (m >= 0 && m <= maxMp)
    {
        mp = m;
    }
}

float Character::getStrength()
{
    return strength;
}

void Character::setStrength(float a)
{
    if (a >= 0)
    {
        strength = a;
    }
}

float Character::getDefense()
{
    return defense;
}

void Character::setDefense(float d)
{
    if (d >= 0)
    {
        defense = d;
    }
}

void Character::attack(Character &target)
{
    std::cout << name << " attacks " << target.name << "!" << std::endl;
}