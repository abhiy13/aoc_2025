# Advent of Code 2025

Solutions for the Advent of Code 2025 challenges written in C++.

## Usage

### Compile

To compile a solution, use `g++`:

```bash
g++ -std=c++11 <filename>.cpp
```

### Run

Execute the compiled program, redirecting input from a text file:

```bash
./a.out < input.txt
```

---

### About `<bits/stdc++.h>`

This project uses the `<bits/stdc++.h>` header file.

-   **What it is:** A non-standard, GNU GCC-specific header that includes all standard C++ library headers.
-   **Why use it:** It's a shortcut for competitive programming to avoid manually including multiple headers like `<iostream>`, `<vector>`, `<string>`, etc.
-   **Warning:** This header is not portable and will only work with compilers that support it (like GCC). It should not be used in production code.
