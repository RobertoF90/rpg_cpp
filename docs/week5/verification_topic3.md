# Week 5 Topic 3 Verification - PASSED

## Code:
```cpp
std::string* enemyPtr = enemies;           // line 134
std::cout << *(enemyPtr + i) << std::endl; // line 192
```

## Output:
```
Enemies in the area: 
Rat - HP: 10
Goblin - HP: 20
Troll - HP: 40
Dragon - HP: 100
```

Pointer arithmetic `*(enemyPtr + i)` iterates through array.

## Status: PASSED