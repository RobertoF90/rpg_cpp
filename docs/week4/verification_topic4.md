# Topic 4 Verification - PASSED

## Code (Lines 140-144):
```cpp
std::vector<std::string> rooms;
rooms.push_back("Entrance");
rooms.push_back("Dark Corridor");
rooms.push_back("Treasure Room");
rooms.push_back("Boss Chamber");
```

## Display (Lines 175-177):
```cpp
for (int i = 0; i < rooms.size(); i++) {
    std::cout << i+1 << " - " <<  rooms[i] << std::endl;
}
```

## Output:
```
You enter the dungeon
You see :1 - Entrance
2 - Dark Corridor
3 - Treasure Room
4 - Boss Chamber
```

## Status: PASSED