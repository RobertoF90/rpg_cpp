# Week 4 Topic 5: Looping Through Collections

## Concept

Use for loops to iterate through arrays and vectors.

## Array Loop

```cpp
std::string enemies[4] = {"Rat", "Goblin", "Troll", "Dragon"};
for (int i = 0; i < 4; i++) {
    std::cout << enemies[i] << std::endl;
}
```

## Vector Loop

```cpp
std::vector<std::string> inventory;
for (int i = 0; i < inventory.size(); i++) {
    std::cout << inventory[i] << std::endl;
}
```

## Your Task 5

Your code at line 165-167 already loops through enemies array.

Complete Task 4 first, then verify both loop through rooms and inventory.