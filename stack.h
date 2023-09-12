//
// Created by khaled on 9/12/23.
//

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <stdint.h>

#define MAX_STACK 10

#define STACK_ENTRY uint8_t

typedef struct stack {
    uint8_t top;
    STACK_ENTRY entry[MAX_STACK];
}Stack;

typedef enum {
    STACK_SUCCESS,          // Operation was successful
    STACK_ERROR,            // Generic error
    STACK_OVERFLOW,         // Stack is full (for Push operation)
    STACK_UNDERFLOW,        // Stack is empty (for Pop and StackTop operations)
    STACK_EMPTY,            // Stack is empty (for StackEmpty function)
    STACK_FULL,             // Stack is full (for StackFull function)
    STACK_INITIALIZED,      // Stack has been initialized (for StackInit function)
    STACK_SIZE,             // Returns the current size of the stack (for StackSize function)
    STACK_CLEAR_SUCCESS     // Stack has been successfully cleared (for ClearStack function)
}en_Stack_Status;

en_Stack_Status Push(STACK_ENTRY, Stack *);
en_Stack_Status Pop(STACK_ENTRY *, Stack *);
en_Stack_Status StackEmpty(Stack *);
en_Stack_Status StackFull(Stack *);
en_Stack_Status StackInit(Stack *);
en_Stack_Status StackTop(STACK_ENTRY *, Stack *);
en_Stack_Status StackSize(Stack *, uint8_t *);
en_Stack_Status ClearStack(Stack *);
en_Stack_Status TraverseStack(Stack *, void (*) (STACK_ENTRY));

#endif //DATA_STRUCTURES_STACK_H
