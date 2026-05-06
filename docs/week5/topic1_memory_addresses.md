# Week 5 Topic 1: Memory Addresses

## Concept Explained

When you create a variable, C++ allocates space in your computer's RAM (Random Access Memory). Each variable needs a place to store its value.

Think of RAM as a big building with many numbered mailboxes. Each mailbox has a unique address number. When you create a variable, the computer gives it a mailbox and remembers the address.

## The & Operator

The ampersand `&` returns the memory address of a variable. This is called "address-of operator".

```cpp
int hp = 15;
```

This creates a variable named `hp` with value 15. Somewhere in RAM, there's a mailbox at address like `0x7ffd3b2c1000` that stores the value 15.

To see that address:
```cpp
std::cout << &hp;  // prints something like 0x7ffd3b2c1000
```

## Why This Matters

1. **Pointers** - Variables that store addresses instead of values
2. **Pass by reference** - Functions can modify original variables
3. **Dynamic memory** - Allocate memory while program runs

## Example in Your RPG

Your existing code already uses addresses without realizing:

In player.cpp line 7:
```cpp
void calculateStats(int level, int& maxHp, int& maxMp, float& attack, float& defense)
```

Notice the `&` after each parameter type. This means the function receives the memory address of the original variables, not copies. When the function changes maxHp, it changes the original variable in main().

## Your Task

Add this to rpg.cpp to see addresses:
```cpp
int hp = 15;
int maxHp = 50;
int gold = 10;

std::cout << "Address of hp: " << &hp << std::endl;
std::cout << "Address of maxHp: " << &maxHp << std::endl;
std::cout << "Address of gold: " << &gold << std::endl;
```

Run and observe the addresses. Each one should be different.