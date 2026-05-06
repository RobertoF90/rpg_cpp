# Week 5 Topic 2: Pointers vs References

## Pointers

A pointer is a variable that stores a memory address instead of a value.

```cpp
int hp = 15;
int* hpPtr = &hp;    // hpPtr stores address of hp
```

- `*` after type means "pointer to int"
- `&hp` gets the address of hp
- Now hpPtr contains something like 0x7ffe2893117c

## Dereferencing

Use `*` to get the value at the address:

```cpp
std::cout << *hpPtr;   // prints 15 (the value at hp's address)
```

## References

A reference is an alias (another name) for a variable:

```cpp
int hp = 15;
int& hpRef = hp;   // hpRef is another name for hp
hpRef = 20;       // changes hp to 20
```

- `&` after type means "reference to int"
- No need to dereference - use it like the original variable

## Key Differences

| Feature | Pointer | Reference |
|---------|---------|----------|
| Declaration | `int* ptr` | `int& ref` |
| Get address | `&var` | (automatic) |
| Get value | `*ptr` | just use `ref` |
| Can be null | yes | no |
| Can reassign | yes | no |

## Your RPG Example

Your player.cpp already uses references:

```cpp
void calculateStats(int level, int& maxHp, int& maxMp, float& attack, float& defense)
```

The `&` makes these parameters references - changes inside the function affect the original variables in main().

## Task

Add pointers to your game to track inventory:

```cpp
std::string* currentWeapon = &weaponEffect;
std::cout << "Current weapon: " << *currentWeapon << std::endl;
```