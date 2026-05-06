# Week 6: Object-Oriented Programming (OOP)

**Roadmap Concept:** Create a Character class with stats, inventory, and methods like attack() and takeDamage()

---

## Topics

### Topic 1: Classes and Objects
- What is a class?
- Creating an object
- Member variables (properties)
- Member functions (methods)

### Topic 2: Public vs Private
- Data encapsulation
- Access specifiers
- Why hide data?

### Topic 3: Constructors
- Default constructor
- Parameterized constructor
- Initialization lists

### Topic 4: Destructors
- What is a destructor?
- When is it called?
- Cleaning up dynamic memory

### Topic 5: Getters and Setters
- Accessing private data
- Controlling modifications
- Validation

---

## Week 6 Goal

Transform your scattered game variables (hp, attack, gold, inventory) into a clean **Character class**.

Instead of:
```cpp
int hp;
int maxHp;
float attack;
std::vector<std::string> inventory;
```

You'll have:
```cpp
class Character {
private:
    int hp;
    int maxHp;
    float attack;
    std::vector<std::string> inventory;

public:
    void takeDamage(int damage);
    void heal(int amount);
    int getHP();
};
```