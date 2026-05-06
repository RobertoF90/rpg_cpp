# Week 6 Topic 1: Classes and Objects

**Roadmap Concept:** What is a class? Creating an object. Member variables and member functions.

---

## 1. Core Concept

### What is a Class?

A class is a blueprint - like a recipe. It defines what an object **will be**, but isn't the object itself.

**Real-world analogy:**
- **Class** = The blueprint for a house
- **Object** = The actual house built from that blueprint

You can build many houses (objects) from one blueprint (class).

### What are Member Variables?

These are variables that belong to a class - they store the object's data.

```cpp
class Character {
    // These are member variables (also called "properties" or "fields")
    std::string name;
    int hp;
    int maxHp;
    float attack;
};
```

### What are Member Functions?

These are functions that belong to a class - they define what the object **can do**.

```cpp
class Character {
public:
    // Member variables
    std::string name;
    int hp;
    int maxHp;
    float attack;

    // Member functions (also called "methods")
    void takeDamage(int damage) {
        hp = hp - damage;
        if (hp < 0) hp = 0;
    }

    void heal(int amount) {
        hp = hp + amount;
        if (hp > maxHp) hp = maxHp;
    }

    void attackEnemy() {
        std::cout << name << " attacks for " << attack << " damage!" << std::endl;
    }
};
```

---

## 2. How to Apply

### Creating an Object

```cpp
// Create an object (instance) of the Character class
Character player;

// Access member variables with dot notation
player.name = "Hero";
player.hp = 100;
player.maxHp = 100;
player.attack = 15.0f;

// Call member functions with dot notation
player.takeDamage(20);      // hp becomes 80
player.heal(10);            // hp becomes 90
player.attackEnemy();       // prints "Hero attacks for 15 damage!"
```

### Multiple Objects

One class, many objects:

```cpp
Character player;
player.name = "Hero";
player.hp = 100;

Character enemy;
enemy.name = "Goblin";
enemy.hp = 30;
enemy.attack = 8.0f;
```

Each object has its own separate data!

---

## 3. Generic Examples

**Example 1 - Simple Player class:**
```cpp
#include <iostream>
#include <string>

class Player {
public:
    std::string name;
    int hp;
    int gold;

    void showStats() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "HP: " << hp << std::endl;
        std::cout << "Gold: " << gold << std::endl;
    }

    void addGold(int amount) {
        gold = gold + amount;
        std::cout << "You got " << amount << " gold!" << std::endl;
    }
};

int main() {
    Player hero;
    hero.name = "Arthur";
    hero.hp = 50;
    hero.gold = 10;

    hero.showStats();
    hero.addGold(25);

    return 0;
}
```

**Example 2 - Enemy class:**
```cpp
class Enemy {
public:
    std::string name;
    int hp;
    int attack;
    int xpReward;

    void takeDamage(int damage) {
        hp = hp - damage;
        if (hp <= 0) {
            std::cout << name << " is defeated!" << std::endl;
        }
    }
};

int main() {
    Enemy goblin;
    goblin.name = "Goblin";
    goblin.hp = 20;
    goblin.attack = 5;
    goblin.xpReward = 10;

    goblin.takeDamage(25);  // Goblin defeated!
    return 0;
}
```

---

## 4. Tasks

**Task 1:** Create a simple Character class

Add this to your game:
```cpp
class Character {
public:
    std::string name;
    int hp;
    int maxHp;
    float attack;

    void takeDamage(int damage) {
        hp = hp - damage;
        if (hp < 0) hp = 0;
        std::cout << name << " takes " << damage << " damage! HP: " << hp << std::endl;
    }

    void heal(int amount) {
        hp = hp + amount;
        if (hp > maxHp) hp = maxHp;
        std::cout << name << " heals " << amount << " HP! HP: " << hp << std::endl;
    }
};
```

**Task 2:** Create objects and use them

```cpp
Character player;
player.name = "Hero";
player.hp = 100;
player.maxHp = 100;
player.attack = 20.0f;

Character enemy;
enemy.name = "Dragon";
enemy.hp = 200;
enemy.maxHp = 200;
enemy.attack = 30.0f;

// Use the methods
player.takeDamage(50);   // Hero takes 50 damage!
enemy.takeDamage(30);    // Dragon takes 30 damage!
player.heal(20);         // Hero heals 20 HP!
```

---

## 5. Detailed Explanation

### Why use classes?

Before classes, you had separate variables:
```cpp
std::string playerName;
int playerHp;
int playerMaxHp;
float playerAttack;
```

Problems with this:
- Hard to manage - what if you want multiple players?
- No organization - functions can modify any variable
- Hard to expand - adding new features means finding all related code

With classes, everything related to a "thing" is grouped together:
```cpp
class Player {
    // All player data in one place
    // All player behaviors in one place
};
```

### The dot operator (.)

When you have an object, use `.` to access its members:

```cpp
object.memberVariable   // Read or write a variable
object.memberFunction() // Call a function
```

---

## 6. Verification

To pass Topic 1, demonstrate:

1. **Class definition** - Create a class with at least 3 member variables
2. **Member functions** - Add at least 2 methods that use the member variables
3. **Create objects** - Make at least 2 objects from the class
4. **Use the objects** - Call functions on the objects

Example showing all:
```cpp
class Character {
public:
    std::string name;
    int hp;
    int maxHp;
    float attack;

    void takeDamage(int damage) {
        hp = hp - damage;
    }
};

int main() {
    Character player;
    player.name = "Hero";
    player.hp = 100;
    player.attack = 15.0f;

    Character enemy;
    enemy.name = "Slime";
    enemy.hp = 30;
    enemy.attack = 5.0f;

    player.takeDamage(10);
    return 0;
}
```