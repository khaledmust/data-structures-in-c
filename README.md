# data-structures-in-c

This repository contain the implementation of some data structures in C language.

## Installation

Just clone the repo and add it to your project's directory and include the required library into your project.

## Header Files Overview

### `stack.h` Documentation

The `stack.h` header file provides an array-based implementation for use in the this project. It defines data structures and functions for creating, managing, and manipulating stacks. Below are the key component's of `stack.h`:
- `STACK_ENTRY`: A typedef defining the data type for stack elements (e.g., `int`, `char`, `struct`).
- `Stack`: A structure representing the stack, including a pointer to stack data, size, and capacity.
- Functions: `Stack_Init`, `Stack_Push`, `Stack_Pop`, `Stack_IsEmpty`, and `Stack_Size` are the primary functions for stack operations.

To use `stack.h` in your code, include it in your source files and follow these steps:

1. Initialize a `Stack` variable.
2. Use the provided functions to push, pop, and query the stack.
3. Handle error conditions returned by the functions, such as stack overflow or underflow.

Refer to `stack.h` comments and the README for usage examples and further details.
