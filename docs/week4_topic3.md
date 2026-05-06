# Week 4 Topic 3: C-Style Strings

## Concept

C-style strings are arrays of characters ending with null '\0'.

```cpp
char name[20] = "Hero";
char weapon[] = "Sword";
```

## Combining

Use strcpy or manually copy:
```cpp
#include <cstring>
strcpy(destination, source);
```

## Length

```cpp
strlen(name)
```

## Your Task 3

This topic is optional for your RPG. You can skip if using std::string instead.