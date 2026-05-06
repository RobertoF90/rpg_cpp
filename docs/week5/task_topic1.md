# Week 5 Topic 1: Memory Addresses

## Concept

Every variable is stored in memory at a specific address. Use & to get the address.

```cpp
int hp = 15;
std::cout << &hp;  // prints memory address like 0x7ffd...
```

The address is where the variable lives in RAM.

## Task

Add this code and run to see addresses:
```cpp
int hp = 15;
int maxHp = 50;
int gold = 10;

std::cout << "hp address: " << &hp << std::endl;
std::cout << "maxHp address: " << &maxHp << std::endl;
std::cout << "gold address: " << &gold << std::endl;
```

Notice: each variable has a unique address.