# Week 2: Control Flow

**Goal:** Learn to make decisions and repeat actions in your code

---

## Topic 1: If/Else Statements

**Concept:** Execute code based on conditions.

```cpp
if (condition) {
    // runs if condition is true
} else {
    // runs if condition is false
}
```

**RPG Example:**
```cpp
if (hp <= 0) {
    std::cout << "You died!" << std::endl;
} else {
    std::cout << "Keep fighting!" << std::endl;
}
```

**Tasks:**
1. Check if player HP is low (below 20) and display a warning
2. Check if attack deals more damage than enemy defense
3. Add else-if for multiple conditions (weakness, normal, resistant)

---

## Topic 2: Switch Statements

**Concept:** Compare one variable against multiple values.

```cpp
switch (variable) {
    case value1:
        // code
        break;
    case value2:
        // code
        break;
    default:
        // code if no match
}
```

**RPG Example:**
```cpp
switch (weapon) {
    case 'sword':
        std::cout << "You swing your sword!" << std::endl;
        break;
    case 'staff':
        std::cout << "You cast a spell!" << std::endl;
        break;
    case 'bow':
        std::cout << "You fire an arrow!" << std::endl;
        break;
    default:
        std::cout << "Unknown weapon!" << std::endl;
}
```

**Tasks:**
1. Create a menu system for weapon selection
2. Use switch for attack type based on enemy weakness
3. Add a default case for invalid input

---

## Topic 3: For Loops

**Concept:** Repeat code a specific number of times.

```cpp
for (int i = 0; i < 5; i++) {
    // runs 5 times (i = 0,1,2,3,4)
}
```

**RPG Example:**
```cpp
for (int round = 1; round <= 3; round++) {
    std::cout << "Round " << round << " begins!" << std::endl;
}
```

**Tasks:**
1. Create a loop that simulates 5 combat rounds
2. Display attack animations (use asterisks or text art)
3. Use a loop to show multiple enemies

---

## Topic 4: While Loops

**Concept:** Repeat code while a condition is true.

```cpp
while (condition) {
    // keeps running until condition is false
}
```

**RPG Example:**
```cpp
while (enemyHp > 0) {
    enemyHp = enemyHp - attackPower;
    std::cout << "Enemy HP: " << enemyHp << std::endl;
}
```

**Tasks:**
1. Create a battle loop that continues until one side wins
2. Add a healing loop that lets player use potions until out
3. Use a while loop with a player choice to continue or flee

---

## Topic 5: Break and Continue

**Concept:** Control loop execution.

**Break** - exit the loop immediately:
```cpp
while (true) {
    if (playerHp <= 0) {
        std::cout << "Game Over!" << std::endl;
        break;  // exit the loop
    }
}
```

**Continue** - skip to next iteration:
```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 5) {
        continue;  // skip turn 5
    }
    std::cout << "Round " << i << std::endl;
}
```

**Tasks:**
1. Use break to end combat when enemy HP reaches 0
2. Use continue to skip player turn when stunned
3. Create a menu loop that only exits when user chooses to quit

---

## Mini Project: Combat Damage Calculator

Create a program that:
1. Has player stats (attack power, weapon type, armor, HP)
2. Has enemy stats (HP, defense, type)
3. Calculates damage based on conditions:
   - Normal attack
   - Critical hit (random chance)
   - Weakness bonus
   - Resistance penalty
4. Uses loops for multiple attack rounds
5. Determines winner when HP reaches 0
6. Displays battle log with damage dealt each round

**Expected structure:**
- Variable declarations for player and enemy
- If/else for damage calculation
- Switch for attack type/weapon
- For or while loop for battle rounds
- Break to end combat

**Bonus:**
- Add healing items
- Add a flee option
- Add randomized damage rolls (use `rand()`)
