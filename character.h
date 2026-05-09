#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character
{
private:
    int hp, maxHp, mp, maxMp;

public:
    Character(
        std::string name = "Bob",

        int level = 1,

        int tileX = 1,
        int tileY = 1

    )
    {
        this->name = name;
        this->level = level;

        this->tileX = tileX;
        this->tileY = tileY;
    };

    std::string name;
    int level;

    int tileX;
    int tileY;

    float strength;
    float defense;

    bool isAlive() const;

    void viewBattleStats();

    int getHp();
    void setHp(int hp);

    int getMaxHp();
    void setMaxHp(int maxHp);

    int getMp();
    int getMaxMp();

    void setMp(int mp);
    void setMaxMp(int maxMp);

    float getStrength();
    void setStrength(float strength);
    float getDefense();
    void setDefense(float defense);

    virtual void attack(Character &target);

    virtual void takeDamage(float damage);
    void healDamage(int heal);
};

#endif
