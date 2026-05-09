# Week 6 Topic 4: Destructors

Cleaning up when objects are destroyed - especially for dynamic memory.

---

## 1. Core Concepts in Detail

A destructor is a special function that runs automatically when an object is destroyed. It has the same name as the class with a tilde (~) in front.

When it runs:
- When a local variable goes out of scope
- When you delete a pointer to an object
- At program end for global variables

Rules:
- Same name as class with ~ prefix
- No return type
- No parameters - only one destructor per class
- Cannot be called directly

---

## 2. Use Cases

- Free dynamic memory (if class uses new, destructor uses delete)
- Close files
- Release resources (network, database)
- Log cleanup messages

Without destructor - memory leak:
```
class Item {
    std::string* name;
    Item() { name = new std::string("Sword"); }
    // No destructor! Memory leaks!
};
```

With destructor:
```
class Item {
    std::string* name;
    Item() { name = new std::string("Sword"); }
    ~Item() { delete name; }
};
```

---

## 3. Generic Examples

Example 1 - Basic:
```
class Player {
public:
    std::string name;
    
    Player(std::string n) : name(n) {}
    
    ~Player() {
        std::cout << name << " destroyed" << std::endl;
    }
};
```

Example 2 - Dynamic memory:
```
class Enemy {
private:
    std::string* name;
    int* hp;
public:
    Enemy(std::string n, int h) {
        name = new std::string(n);
        hp = new int(h);
    }
    ~Enemy() {
        delete name;
        delete hp;
    }
};
```

---

## 4. Tasks

Add a destructor to your Character class:

```
~Character() {
    std::cout << "Character destroyed" << std::endl;
}
```

Your class doesn't use dynamic memory yet, so this is optional. The real use comes when you add pointers later.