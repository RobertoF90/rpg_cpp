# Week 4 Topic 4: std::string

## Concept

`std::string` is C++ object for text. Handles memory automatically.

```cpp
std::string playerName = "Hero";
std::string weapon = "sword";
```

## Combine

```cpp
std::string message = playerName + " wields " + weapon;
```

## Length

```cpp
int len = playerName.length();
```

## Compare

```cpp
if (playerName == "Hero") { }
```

## Your Task 4

Your Task 4: Create a vector of room names using std::string:
```cpp
std::vector<std::string> rooms;
rooms.push_back("Entrance");
rooms.push_back("Dark Corridor");
rooms.push_back("Treasure Room");
rooms.push_back("Boss Chamber");
```