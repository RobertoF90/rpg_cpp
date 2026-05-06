# C++ RPG Developer Roadmap

A structured learning plan to go from C++ beginner to RPG game developer.

---

## Phase 1: Foundations (Weeks 1-4)

**Goal:** Understand core C++ syntax and programming basics

### Week 1: Getting Started
- Variables and data types (int, float, double, char, bool)
- Input/Output with std::cin and std::cout
- Basic arithmetic operations
- Comments

**RPG Mini Project:** Character stat viewer - display a character's name, level, HP, and gold using variables

### Week 2: Control Flow
- If/else statements
- Switch statements
- For loops
- While loops
- Break and continue

**RPG Mini Project:** Combat damage calculator - calculate damage based on weapon, armor, and random rolls

### Week 3: Functions
- Function declaration and definition
- Parameters and return values
- Function overloading
- Scope and namespaces
- Header files (.h) and .cpp files

**RPG Mini Project:** Stat calculator functions - separate functions for calculating damage, XP needed for level-up, critical hit chance

### Week 4: Arrays and Strings
- C-style arrays
- std::vector
- C-style strings
- std::string
- Looping through collections

**Milestone RPG:** Text-based dungeon crawler with multiple rooms, enemies, and inventory using vectors

---

## Phase 2: Intermediate Concepts (Weeks 5-8)

**Goal:** Master memory management and object-oriented programming

### Week 5: Pointers and References
- Memory addresses
- Pointers vs references
- Pointer arithmetic
- Dynamic memory (new/delete)
- Null pointers

**RPG Concept:** Managing inventory slots with pointers - understand how items are stored and referenced

### Week 6: Object-Oriented Programming (OOP)
- Classes and objects
- Public vs private
- Constructors and destructors
- Member functions
- Getter and setter methods

**RPG Concept:** Create a Character class with stats, inventory, and methods like attack() and takeDamage()

### Week 7: Advanced OOP
- Inheritance
- Polymorphism
- Virtual functions
- Abstract classes and interfaces
- Composition

**Milestone RPG:** Turn-based battle system with character classes (Warrior, Mage, Rogue) - each with unique stats and abilities

### Week 8: STL Containers & Algorithms
- std::map
- std::set
- std::list
- Iterators
- std::sort, std::find, std::for_each

**RPG Concept:** Item database using map, party members using vector, sorting inventory by value or type

---

## Phase 3: RPG Game Development Fundamentals (Weeks 9-12)

**Goal:** Apply C++ to real RPG mechanics

### Week 9: File I/O and Serialization
- Reading/writing files
- Saving game state
- Loading level data
- JSON basics

**RPG Concept:** Save/load character progress - inventory, equipped items, quest progress, map exploration

### Week 10: Game Loop and State Machines
- Game loop architecture
- State machine pattern
- Menu systems (main menu, inventory, shop, battle)
- Pause functionality

**RPG Concept:** Menu-driven RPG - navigate between town, inventory, battle, and rest screens

### Week 11: Collision Detection & Grid Systems
- Tile-based movement
- Grid systems (2D arrays)
- Pathfinding basics (A* intro)
- Zone/trigger systems

**RPG Concept:** Top-down map with walkable/non-walkable tiles - move a character around a village

### Week 12: Graphics Fundamentals
- Using a simple graphics library (SFML or raylib)
- Drawing tiles and sprites
- Handling user input (WASD)
- Animation basics (sprite sheets)

**Milestone RPG:** Tile-based RPG map with character movement

---

## Phase 4: Full RPG Development (Weeks 13-16)

**Goal:** Build complete RPG systems with graphics

### Week 13-14: SFML/raylib Deep Dive
- Window management
- Textures and sprites
- Tile maps and tile maps editors (Tiled)
- Camera/view following player
- Sound and music
- Time management (cooldowns, animations)

**Game Project:** Dungeon crawler with multiple floors, random encounters, and a minimap

### Week 15-16: RPG Systems Implementation
- Quest system (main quest, side quests, objectives)
- Dialogue system (branching conversations)
- Crafting system (combine items)
- Equipment/stats system (gear upgrades)

**Milestone RPG:** Complete RPG demo with town, dungeons, combat, inventory, and quest log

---

## Phase 5: Advanced RPG Development (Weeks 17-20)

**Goal:** Master performance and professional practices for larger RPGs

### Week 17-18: Performance Optimization
- Profiling and benchmarking
- Memory pools for entities
- Object pooling for bullets/effects
- Cache-friendly data structures
- Lazy loading for large worlds

### Week 19-20: Design Patterns for RPGs
- Entity-Component System (ECS)
- Observer pattern for events (damage taken, quest complete)
- Command pattern for undo/redo
- State machine for AI behavior
- Factory pattern for spawning

**Final Project:** 2D RPG with overworld map, towns, dungeons, turn-based combat, and save system

---

## RPG Milestone Summary

| Phase | Milestone RPG | Core C++ Concepts |
|-------|---------------|-------------------|
| 1 | Text Dungeon Crawler | Vectors, functions, loops |
| 2 | Turn-based Battle System | Classes, inheritance, polymorphism |
| 3 | Menu-driven RPG | State machines, file I/O |
| 3 | Tile Map Explorer | 2D arrays, grid systems |
| 4 | Full Dungeon Crawler | SFML, tile maps, camera, audio |
| 5 | Complete 2D RPG | ECS, design patterns, optimization |

---

## RPG Mechanics → C++ Concepts Mapping

Understanding RPGs helps you understand these C++ concepts:

| RPG Concept | C++ Concept |
|-------------|-------------|
| Character stats (HP, MP, STR) | Class member variables |
| Character abilities | Class member functions |
| Warrior/Mage inherit from Character | Inheritance & polymorphism |
| Inventory items | std::vector or std::map |
| Equipping/unequipping gear | Reference/pointer management |
| Save game files | File I/O & serialization |
| Walkable vs blocked tiles | 2D arrays |
| AI behavior (idle, chase, attack) | State machines |
| Damage over time, buffs | Timer systems |
| Random loot drops | Random number generation |

---

## Recommended Tools

### Compilers
- **g++** (GCC) - Default on Linux/WSL
- **MSVC** - For Windows/Visual Studio
- **Clang** - Alternative compiler

### Text Editors / IDEs
- **VS Code** - Lightweight with C++ extensions (recommended)
- **Visual Studio** - Full IDE with great debugging
- **CLion** - JetBrains C++ IDE (paid)

### Graphics Libraries for RPGs
1. **raylib** - Easiest, great for beginners, perfect for 2D
2. **SFML** - Simple Fast Media Library, good for sprites
3. **SDL2** - More control, steeper learning curve
4. **Dear ImGui** - For debug tools and UI

### Game Engines for RPGs
- **Unreal Engine** - Industry standard, C++ first, great for large RPGs
- **Godot** - Open source, C++ support, 2D focused
- **O3DE** - Open 3D Engine

### RPG-Specific Tools
- **Tiled Map Editor** - Create tile maps (free)
- **LDtk** - Level editor (free, modern)
- **RPG Maker** - No-code RPG creation (good for reference)

---

## Daily Practice Routine

| Day | Activity | Time |
|-----|----------|------|
| Mon-Fri | Concept study + coding exercises | 1-2 hours |
| Saturday | RPG project work | 2-3 hours |
| Sunday | Review week's code + rest | 1 hour |

---

## Inspiration Games (What You'll Build)

| Milestone | Inspired By | Type |
|-----------|-------------|------|
| Week 4 | Early roguelikes | Text terminal |
| Week 7 | Final Fantasy 1-6 | Turn-based battle |
| Week 11 | Zelda (top-down) | Tile movement |
| Week 14 | Dragon Quest | Overworld + battles |
| Week 16 | Baldur's Gate (simplified) | Full RPG demo |
| Week 20 | Chrono Trigger | Complete 2D RPG |

---

## Additional Resources

### Books
- *C++ Primer* by Lippman - Comprehensive reference
- *Beginning C++ Game Programming* by Dawson - Game-focused
- *Game Programming Patterns* by Nystrom - Essential for RPGs
- *The Art of Game Design* by Jesse Schell - Game design theory

### Practice Sites
- [LeetCode](https://leetcode.com) - Algorithm practice
- [Exercism C++](https://exercism.org) - Structured exercises

### Communities
- r/cpp - C++ subreddit
- r/gamedev - Game development subreddit
- r/RPGMaker - RPG development community
- GameDev.net - Long-standing game dev community

### YouTube Channels
- The Cherno - Game development with C++
- ThinMatrix - Java but great game dev concepts
- Let Us Code - C++ tutorials for beginners
