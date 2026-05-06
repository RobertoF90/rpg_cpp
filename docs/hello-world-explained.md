# C++ Basics: Hello World Explained

```cpp
#include <iostream>   // includes input/output library

int main() {          // main function - program starts here
    std::cout << "Hello, World!" << std::endl;  // prints text to screen
    return 0;          // tells OS program succeeded
}                      // end of program
```

## Key Concepts

| Element | Purpose |
|---------|---------|
| `#include` | Brings in pre-written code (like importing a library) |
| `int main()` | The entry point every C++ program needs |
| `std::cout` | Prints output to the console |
| `<<` | The "put to" operator (sends text to cout) |
| `std::endl` | Adds a newline at the end |
| `return 0` | Signals successful program completion |

## How to Compile and Run

```bash
g++ hello.cpp -o hello
./hello
```

## Output

```
Hello, World!
```
