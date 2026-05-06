# Week 4 Topic 2: std::vector

## Concept

`std::vector` is a dynamic array that can grow and shrink.

```cpp
#include <vector>

std::vector<std::string> inventory;
inventory.push_back("Potion");
inventory.push_back("Torch");
```

## Access and Size

```cpp
inventory[0];           // first item
inventory.size();         // number of items
```

## Loop Through

```cpp
for (int i = 0; i < inventory.size(); i++) {
    std::cout << inventory[i] << std::endl;
}
```

## Your Task 2

Already complete in rpg.cpp:
- Line 106-110: inventory vector with Potion, Potion, Torch