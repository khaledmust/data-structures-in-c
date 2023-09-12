#include <stdio.h>
#include "stack.h"

void Display(STACK_ENTRY element) {
    printf("%d\t", element);
}

int main() {
    printf("Hello, World!\n");
    Stack myStack;
    StackInit(&myStack);
    Push(1, &myStack);
    Push(2, &myStack);
    Push(3, &myStack);
    TraverseStack(&myStack, &Display);
    STACK_ENTRY tmp;
    Pop(&tmp, &myStack);
    TraverseStack(&myStack, &Display);
    return 0;
}
