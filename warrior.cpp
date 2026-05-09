#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "warrior.h"

void Warrior::initializeClass()
{

    setMaxHp(level * 25);
    setHp(getMaxHp());
    setMaxMp(level * 10);
    setMp(getMaxMp());
    setStrength(level * 2.5f);
    setDefense(level * 2.0f);
}

// SKILLS

void Warrior::viewSkills()
{
    std::cout << std::endl
              << " === SKILLS === " << std::endl
              << std::endl;
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            std::cout << "[Skill]";
        }
        std::cout << std::endl;
    }
}
