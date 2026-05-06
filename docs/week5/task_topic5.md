# Week 5 Topic 5: Null Pointers

**Roadmap Concept:** Handling empty pointers safely - what happens when a pointer points to nothing.

**Tasks:**
1. Understand what nullptr is
2. Check if pointer is null before using
3. Use null in conditional logic

---

## 1. Core Concept

A null pointer is a pointer that points to nothing - it's like having an empty slot in your inventory.

In older C++, people used `NULL` or `0`. Modern C++ uses `nullptr` - it's cleaner and safer.

Using a null pointer causes a crash (segmentation fault). Always check before using!

---

## 2. How to Apply

**Declare a null pointer:**
```cpp
int* emptyPtr = nullptr;
```

**Check if null:**
```cpp
if (pointer != nullptr) {
    // safe to use
}
```

**In conditional (also works):**
```cpp
if (pointer) {
    // pointer is NOT null
}
```

---

## 3. Generic Examples

**Example 1 - Safe pointer use:**
```cpp
std::string* weapon = nullptr;

// Later, maybe set it
weapon = new std::string("Sword");

// Check before using
if (weapon != nullptr) {
    std::cout << *weapon << std::endl;
}

delete weapon;
weapon = nullptr;
```

**Example 2 - Null as "no choice":**
```cpp
int* selectedItem = nullptr;

void pickItem(int choice) {
    if (choice == 1) {
        selectedItem = new std::string("Potion");
    } else {
        selectedItem = nullptr;  // nothing selected
    }
}

void useItem() {
    if (selectedItem == nullptr) {
        std::cout << "Nothing to use!" << std::endl;
    } else {
        std::cout << "Using " << *selectedItem << std::endl;
    }
}
```

---

## 4. Tasks

**Task 1:** Add a null check to your game
```cpp
std::string* equippedWeapon = nullptr;

// Later when weapon is equipped:
equippedWeapon = new std::string("Excalibur");

// Before using:
if (equippedWeapon != nullptr) {
    std::cout << "Your weapon: " << *equippedWeapon << std::endl;
}
```

**Task 2:** Use null to represent "no weapon"
```cpp
std::string* currentWeapon = nullptr;

// In battle, check if armed:
if (currentWeapon) {
    attack += 5;
} else {
    std::cout << "You fight with your fists!" << std::endl;
}
```

---

## 5. Detailed Explanation

### What is nullptr?

Think of a pointer as a address card. Sometimes you have no address to write down - the card is blank. That's `nullptr` - a pointer that points to nothing.

In old C++ (before 2011), people used `NULL` (which is just `0`) or even just `0` directly. This was confusing because `0` could be a number or a null pointer. Modern C++11 introduced `nullptr` - it's a special keyword that always means "no address, nothing".

### Why does using a null pointer crash?

When you dereference a pointer (use `*ptr`), you're going to the memory address it points to. If it's null, there's no valid address - you're going to memory location 0 (or close to it). This memory is either:
- Reserved for the operating system
- Empty/invalid

Accessing it causes a "segmentation fault" - your program crashes.

### Real-world analogy

Imagine you're playing a board game:
- **Normal pointer**: A player token on a square - you can see what's there
- **Null pointer**: No token - the square is empty
- **Dereferencing null**: Trying to look at what's on a square with no token → confusion/crash

### The golden rule

**Always check if a pointer is null before dereferencing it.**

```cpp
// BAD - could crash!
std::cout << *myWeapon << std::endl;

// GOOD - safe
if (myWeapon != nullptr) {
    std::cout << *myWeapon << std::endl;
}
```

### nullptr in conditionals

Here's the cool part - pointers are "truthy":

```cpp
if (ptr) {
    // ptr is NOT null
}

if (!ptr) {
    // ptr IS null
}
```

This works because `nullptr` converts to `false`, and any valid address converts to `true`.

---

## 6. Verification

To pass Topic 5, demonstrate:

1. **Null pointer declaration** - Start with `nullptr`
2. **Conditional check** - Use `if (ptr)` or `if (ptr != nullptr)` before dereferencing
3. **Apply to your game** - Use null to represent "no weapon equipped" and check it in battle

Example in your game code:
```cpp
std::string* currentWeapon = nullptr;

// When player equips a weapon:
currentWeapon = new std::string("Sword");

// In battle attack:
if (currentWeapon != nullptr) {
    std::cout << "You swing your " << *currentWeapon << "!" << std::endl;
} else {
    std::cout << "You punch the enemy!" << std::endl;
}

// Clean up:
delete currentWeapon;
currentWeapon = nullptr;
```

**Week 5 Complete when all 5 topics verified!**

- Topic 1: Memory Addresses (&) ✓
- Topic 2: Pointers vs References ✓
- Topic 3: Pointer Arithmetic ✓
- Topic 4: Dynamic Memory (new/delete) ✓
- Topic 5: Null Pointers → **IN PROGRESS**