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

### `linked_list_stack.h` Documentation

The `linked_list_stack.h` header file defines a linked list-based stack data structure. It is designed to offer a consistent interface and return values with the array-based stack defined in `stack.h`.

#### Functions

The functions provided by `linked_list_stack.h` have the same names and return values as those in `stack.h`:

- `Stack_Init`: Initialize an empty linked list stack.
- `Stack_Push`: Push an element onto the stack.
- `Stack_Pop`: Pop an element from the stack.
- `Stack_IsEmpty`: Check if the stack is empty.
- `Stack_Size`: Get the current size of the stack.

### Using `linked_list_stack.h`

To use the linked list stack in your project while maintaining portability with the array-based stack, follow these steps:

1. Include `linked_list_stack.h` in your source files.
2. Create a `LinkedListStack` variable.
3. Use the provided functions to push, pop, and query the stack.
4. Handle error conditions returned by the functions, such as stack underflow or overflow.

Here's a simple code example that demonstrates the consistency between the array-based stack and linked list stack:

```c
#include <stdio.h>
#include "linked_list_stack.h" // Use the linked list stack header for portability

int main() {
    Stack llStack;
    Stack_Init(&llStack); // Initialize using the linked list stack function

    // Push elements onto the stack
    Stack_Push(&llStack, 42);
    Stack_Push(&llStack, 67);
    Stack_Push(&llStack, 15);

    // Pop elements from the stack
    int value;
    Stack_Pop(&llStack, &value);
    printf("Popped value: %d\n", value);

    // Check if the stack is empty
    if (Stack_IsEmpty(&llStack)) {
        printf("The stack is empty.\n");
    } else {
        printf("The stack is not empty.\n");
    }

    // Get the current size of the stack
    int size = Stack_Size(&llStack);
    printf("Stack size: %d\n", size);

    return 0;
}
