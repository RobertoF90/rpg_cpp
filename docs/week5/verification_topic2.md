# Week 5 Topic 2 Verification - PASSED

## Code (Lines 107-110):
```cpp
std::string* weaponPtr = &weaponEffect;
std::cout << "Pointer address: " << weaponPtr << std::endl;
std::cout << "dereferenced: " << *weaponPtr << std::endl;
```

## Output:
```
Pointer address: 0x7ffc052c81c0
dereferenced: bonk
```

- Pointer stores an address
- Dereferencing gets the value

## Status: PASSED