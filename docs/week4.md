# Week 4: Arrays and Strings

**Goal:** Store and work with multiple values using arrays and strings

---

## Topic 1: C-Style Arrays

**Concept:** An array stores multiple values of the same type in one variable. Access each item by its position (index).

```cpp
// Declare an array with 4 elements
std::string enemies[4] = {"Rat", "Goblin", "Troll", "Dragon"};

// Access element at index 0, 1, 2, or 3
enemies[0]  // "Rat"
enemies[1]  // "Goblin"
enemies[2]  // "Troll"
enemies[3]  // "Dragon"
```

**Important:** Arrays start at index 0, not 1. The last index is always (size - 1).

**RPG Example:**
```cpp
std::string enemies[4] = {"Rat", "Goblin", "Troll", "Dragon"};
int randomIndex = rand() % 4;  // gives 0, 1, 2, or 3
std::cout << "A " << enemies[randomIndex] << " appears!" << std::endl;
```

---

## Topic 2: Looping Through Arrays

**Concept:** Use a for loop to iterate through all elements in an array.

```cpp
std::string enemies[4] = {"Rat", "Goblin", "Troll", "Dragon"};

for (int i = 0; i < 4; i++) {
    std::cout << "Enemy " << i << ": " << enemies[i] << std::endl;
}
```

**RPG Example:**
```cpp
// Display all available enemies
std::cout << "Enemies in this area:" << std::endl;
for (int i = 0; i < 4; i++) {
    std::cout << i << ". " << enemies[i] << std::endl;
}
```

---

## Topic 3: std::string

**Concept:** `std::string` is a C++ object for text. Unlike C-style strings, it handles memory automatically.

```cpp
std::string playerName = "Hero";
std::string enemyName = "Dragon";

// Combine strings
std::string message = playerName + " defeats " + enemyName;

// Get length
int length = playerName.length();

// Compare strings
if (playerName == "Hero") {
    std::cout << "Welcome, Hero!" << std::endl;
}
```

**RPG Example:**
```cpp
std::string weapon = "sword";
std::string weaponEffect;

if (weapon == "sword") {
    weaponEffect = "*slashhh*";
} else if (weapon == "staff") {
    weaponEffect = "*whoosh*";
}
```

---

## Topic 4: std::vector

**Concept:** A vector is a dynamic array that can grow and shrink. Unlike C-style arrays, you don't need to know the size beforehand.

```cpp
#include <vector>

// Create an empty vector
std::vector<std::string> inventory;

// Add items
inventory.push_back("Potion");
inventory.push_back("Sword");

// Access items (starts at index 0)
inventory[0]    // "Potion"
inventory[1]    // "Sword"

// Get size
int size = inventory.size();
```

**RPG Example:**
```cpp
std::vector<std::string> party;
party.push_back("Hero");
party.push_back("Cleric");
party.push_back("Mage");

for (int i = 0; i < party.size(); i++) {
    std::cout << "Party member " << i << ": " << party[i] << std::endl;
}
```

---

## Tasks

### Task 1: Enemies Array (C-Style Array)
x1. Your code at line 117 already has: `std::string enemies[4] = {"Rat", "Goblin", "Troll", "Dragon"};`
x2. Add another array for enemy stats (HP): `int enemyHpList[4] = {10, 20, 40, 100};`
x3. Use `enemies[enemy]` to display the correct name when the enemy attacks (you already fixed this - good!)

### Task 2: Display All Enemies (For Loop)
x1. Create a loop that displays all 4 enemies with their index
x2. Print: "Enemy 0: Rat, Enemy 1: Goblin, etc."
x3. Show this when player enters the dungeon

### Task 3: Inventory Vector (std::vector)
x1. Create a vector for player inventory: `std::vector<std::string> inventory;`
x2. Add starting items: `inventory.push_back("Potion");` (add 2 potions)
x3. Add `inventory.push_back("Torch");`
x4. Display inventory showing all items with their slot number

### Task 4: Room Names (std::string + Vector)
x1. Create a vector of room names: `std::vector<std::string> rooms;`
x2. Add rooms: "Entrance", "Dark Corridor", "Treasure Room", "Boss Chamber"
x3. Display the current room the player is in

### Task 5: Dungeon Rooms (Combined)
x1. Create a vector for room descriptions
x2. Add description for each room
x3. Allow player to move between rooms (choose direction)

---

## Mini Project: Text Dungeon Crawler

Create a program that:
1. Has multiple rooms stored in a vector ( Entrance, Hallway, Armory, Treasure Room,Exit)
2. Has multiple enemies in an array with matching HP values
3. Has an inventory vector that can hold items
4. Allows player to move between rooms
5. Random encounters when entering rooms
6. Display current room name and description

**Expected structure:**
```cpp
std::vector<std::string> rooms = {"Entrance", "Hallway", "Armory", "Treasure Room"};
std::vector<std::string> descriptions = {"A dark entrance", "A long hallway", "Weapons on walls", "Gold everywhere!"};
std::string enemies[4] = {"Rat", "Goblin", "Skeleton", "Dragon"};
std::vector<std::string> inventory;
```

**Bonus:**
- Add enemy HP array matching the enemies array
- Add room connections (which rooms connect to which)
- Add item pickups to inventory
- Display inventory count