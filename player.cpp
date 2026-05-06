#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "player.h"

void Player::checkHp()
{
    int alert = getMaxHp() * 0.2;
    if (getHp() <= alert)
    {
        std::cout << "HP LOW!!!" << std::endl;
    }
}

void Player::setName()
{
    std::cout << "Enter your name: ";
    std::cin >> name;
}

void Player::viewCharacter()
{
    std::cout << "=== CHARACTER ===" << std::endl
              << std::endl;
    std::cout << std::left << std::setw(15) << "Name: " << name << std::endl;
    std::cout << std::left << std::setw(15) << "HP: " << getHp() << " / " << getMaxHp() << std::endl;
    std::cout << std::left << std::setw(15) << "MP: " << getMp() << " / " << getMaxMp() << std::endl;
    std::cout << std::left << std::setw(15) << "Strength: " << getStrength() << std::endl;
    std::cout << std::left << std::setw(15) << "Defense: " << getDefense() << std::endl;
    std::cout << std::left << std::setw(15) << "Level: " << level << std::endl;
    std::cout << "XP for next level: " << xpNeeded << std::endl
              << std::endl;
}

void Player::attack(Character &target)
{
    Character::attack(target);
    std::cout << "Player attacks!" << std::endl;
}

void Player::takeDamage(float damage)
{
    Character::takeDamage(damage); // Call the base class method first to reduce HP

    if (getHp() <= 0)
    {
        std::cout << name << " has been defeated!" << std::endl;
    }
    else
    {
        std::cout << name << " takes " << damage << " damage!" << std::endl;

        Character::viewBattleStats(); // Show updated HP after taking damage
    }
}
