# Week 5 Topic 4: Dynamic Memory (new/delete)

**Roadmap Concept:** Managing inventory slots with pointers - understand how items are stored and referenced.

**Tasks:**
1. Add `new std::string` to create a dynamic weapon variable
2. Print the weapon using the pointer
3. Free with `delete` and set to `nullptr`

---

## 1. Core Concept

When you declare a regular variable like `int hp = 15`, the compiler decides where it goes in memory before the program runs. This uses stack memory.

Dynamic memory uses the heap. You request memory while the program runs using the word `new`. You must free it with `delete`.

Use this when you do not know how much memory you need until the program is actually running.

---

## 2. How to Apply

**Allocate a single variable:**
```cpp
int* hp = new int;
*hp = 15;
```

**Allocate and initialize:**
```cpp
int* health = new int(50);
```

**Allocate an array:**
```cpp
std::string* items = new std::string[5];
items[0] = "Potion";
```

**Free a single variable:**
```cpp
delete hp;
hp = nullptr;
```

**Free an array:**
```cpp
delete[] items;
items = nullptr;
```

---

## 3. Generic Examples

**Example 1 - Dynamic enemy:**
```cpp
int* enemyHP = new int(100);
std::cout << "Enemy HP: " << *enemyHP << std::endl;
*enemyHP -= 30;
std::cout << "Enemy HP: " << *enemyHP << std::endl;
delete enemyHP;
enemyHP = nullptr;
```

**Example 2 - Dynamic inventory:**
```cpp
std::string* loot = new std::string[3];
loot[0] = "Gold";
loot[1] = "Key";
std::cout << loot[0] << std::endl;
delete[] loot;
loot = nullptr;
```

---

## 4. Tasks

**Task 1:** Add a dynamic weapon to your game
```cpp
std::string* equippedWeapon = new std::string("Excalibur");
std::cout << "You wield: " << *equippedWeapon << std::endl;
delete equippedWeapon;
equpliedWeapon = nullptr;
```

**Task 2:** Add a dynamic loot array
```cpp
int numDrops = 3;
std::string* loot = new std::string[numDrops];
loot[0] = "Gold";
loot[1] = "Potion";
loot[2] = "Key";
std::cout << loot[0] << std::endl;
delete[] loot;
loot = nullptr;
```