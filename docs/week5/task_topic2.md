# Week 5 Topic 2: Pointers vs References

## 1. Core Concept (Expanded)

### What is a Pointer?

A pointer is a variable that stores a memory address (where another variable lives in RAM) instead of storing a value directly.

Think of it like a house address written on a piece of paper - the paper (pointer) doesn't contain the house (data), it contains where to find the house.

Every variable in C++ lives somewhere in memory. A pointer tells you that location.

**Syntax:**
- `int* ptr` means "pointer to int"
- `&variable` means "get the address of variable"

### What is a Reference?

A reference is an alias - another name for an existing variable. When you create a reference, you're giving the same variable two names.

Think of it like a nickname - "Bob" and "Robert" are both you.

**Syntax:**
- `int& ref` means "reference to int"

The key difference: a pointer can be empty (null), but a reference must always refer to something.

### Real-World Analogy

```
House (variable):     int hp = 15;
House address:        &hp = 0x7ffe... (some memory location)
Map with address:     int* hpPtr = &hp;    (pointer to hp)
Nickname:             int& hpRef = hp;     (reference to hp)
```

## 2. How to Apply

### Pointer Usage
```cpp
int hp = 15;
int* hpPtr = &hp;           // hpPtr now holds hp's address

*hpPtr;                    // dereference - gets value 15
*hpPtr = 50;               // changes hp to 50 through pointer
```

### Reference Usage
```cpp
int hp = 15;
int& hpRef = hp;           // hpRef is now another name for hp
hpRef = 50;               // changes hp to 50 directly
```

### Your Existing Code Reference

Look at player.cpp line 7:
```cpp
void calculateStats(int level, int& maxHp, int& maxMp, float& attack, float& defense) {
    maxHp = level * 25;
    maxMp = level * 10;
    attack = level * 2.5f;
    defense = level * 2.0f;
}
```

The `int& maxHp` is a reference parameter. When you call this function in rpg.cpp:
```cpp
Player::calculateStats(level, maxHp, maxMp, attack, defense);
```

The function modifies `maxHp` directly - changes are saved to the original variable. This is pass-by-reference.

If it were pass-by-value (without `&`), the function would work on copies and changes would be lost.

## 3. Generic Examples

### Pointer Example
```cpp
int health = 100;
int* healthPtr = &health;        // store address

std::cout << health;             // prints 100
std::cout << *healthPtr;       // prints 100 (dereference)

*healthPtr = 50;               // change through pointer
std::cout << health;           // now prints 50
```

### Reference Example
```cpp
int health = 100;
int& healthRef = health;      // create alias

healthRef = 50;              // change through reference
std::cout << health;         // prints 50
```

### Null Pointer
```cpp
int* emptyPtr = nullptr;       // null pointer - points to nothing
if (emptyPtr == nullptr) {
    std::cout << "No address"; 
}
```

## 4. Task

Add a pointer to track the current weapon in your game:

```cpp
std::string weaponEffect = "*slashhh*";
std::string* weaponPtr = &weaponEffect;

std::cout << "Pointer address: " << weaponPtr << std::endl;
std::cout << "Dereferenced: " << *weaponPtr << std::endl;
```

Or add a reference to modify a variable directly.