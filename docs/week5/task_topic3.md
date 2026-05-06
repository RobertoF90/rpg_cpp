# Week 5 Topic 3: Pointer Arithmetic

## 1. Core Concept

Pointer arithmetic lets you move through array elements by adding or subtracting from the pointer.

When you add 1 to a pointer, it moves to the next element's address (not just +1 byte, but the size of that data type).

## 2. How to Apply

```cpp
int items[3] = {10, 20, 30};
int* itemPtr = items;    // points to first element (items[0])

itemPtr + 1;             // moves to items[1]
itemPtr + 2;             // moves to items[2]
```

## 3. Generic Examples

```cpp
std::string enemies[4] = {"Rat", "Goblin", "Troll", "Dragon"};
std::string* enemyPtr = enemies;

std::cout << *enemyPtr;      // "Rat"
enemyPtr++;
std::cout << *enemyPtr;     // "Goblin"
enemyPtr++;
std::cout << *enemyPtr;     // "Troll"
```

## 4. Task

Add a loop using pointer arithmetic to display enemies:

```cpp
std::string enemies[4] = {"Rat", "Goblin", "Troll", "Dragon"};
std::string* enemyPtr = enemies;

for (int i = 0; i < 4; i++) {
    std::cout << *(enemyPtr + i) << std::endl;
}
```