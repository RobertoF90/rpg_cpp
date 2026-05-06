# Week 5 Topic 1 Verification - PASSED

## Code (Lines 95-97):
```cpp
std::cout << "Address of hp: " << &hp << std::endl;
std::cout << "Address of maxHp: " << &maxHp << std::endl;
std::cout << "Address of gold: " << &gold << std::endl;
```

## Output:
```
Address of hp: 0x7ffe2893117c
Address of maxHp: 0x7ffe28931180
Address of gold: 0x7ffe28931188
```

Each variable has a unique memory address. The addresses differ by 4 bytes (size of int).

## Status: PASSED