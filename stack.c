//
// Created by khaled on 9/12/23.
//

#include "stack.h"

#define STACK_INIT 0

/**
 * @brief Pushes an element to the top of the stack.
 * @param element The element to be pushed onto the stack.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 * @return STACK_OVERFLOW if the stack is full.
 */
en_Stack_Status Push(STACK_ENTRY element, Stack *pStack) {
    if (pStack->top != MAX_STACK) {
        pStack->entry[pStack->top++] = element;
        return STACK_SUCCESS;
    } else {
        return STACK_OVERFLOW;
    }
}

/**
 * @brief Pops out the top element from the stack.
 * @param pElement Address of the element to store the popped element.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 * @return STACK_UNDERFLOW if the stack is empty.
 */
en_Stack_Status Pop(STACK_ENTRY *pElement, Stack *pStack) {
    if (pStack->top != STACK_EMPTY) {
        *pElement = pStack->entry[--(pStack->top)];
        return STACK_SUCCESS;
    } else {
        return STACK_UNDERFLOW;
    }
}

/**
 * @brief Checks if the stack is empty.
 * @param pStack Address of the stack.
 * @return STACK_EMPTY if stack is empty.
 * @return STACK_ERROR on failure.
 */
en_Stack_Status StackEmpty(Stack *pStack) {
    if (pStack->top == STACK_EMPTY) {
        return STACK_EMPTY;
    } else {
        return STACK_ERROR;
    }
}

/**
 * Checks if the stack is full.
 * @param pStack Address of the stack.
 * @return STACK_FULL if the stack is full.
 * @return STACK_ERROR on failure.
 */
en_Stack_Status StackFull(Stack *pStack) {
    if (pStack->top == MAX_STACK) {
        return STACK_FULL;
    } else {
        return STACK_ERROR;
    }
}

/**
 * Initializes the top of the stack to the initial value.
 * @param pStack Address of the stack.
 * @return STACK_INITIALIZED on success.
 */
en_Stack_Status StackInit(Stack *pStack) {
    pStack->top = STACK_INIT;
    return STACK_INITIALIZED;
}

/**
 * Gets the top-most element from the stack.
 * @param pElement Address of the element to store the top-most element value.
 * @param pStack Address of the stack.
 * @return STACK_UNDERFLOW if stack is empty.
 * @return STACK_SUCCESS on success.
 */
en_Stack_Status StackTop(STACK_ENTRY *pElement, Stack *pStack) {
    if (pStack->top == STACK_INIT) {
        return STACK_UNDERFLOW;
    } else {
        *pElement = pStack->entry[(pStack->top) - 1];
        return STACK_SUCCESS;
    }
}

/**
 * Gets the size of the stack.
 * @param pStack Address of the stack.
 * @param pSize Address of the variable to store the size to.
 * @return STACK_SUCCESS on success.
 */
en_Stack_Status StackSize(Stack *pStack, uint8_t *pSize) {
    *pSize = pStack->top;
    return STACK_SUCCESS;
}

/**
 * Clears the stack.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 */
en_Stack_Status ClearStack(Stack *pStack) {
    pStack->top = STACK_INIT;
    return STACK_SUCCESS;
}

/**
 * @brief Prints out all the elements of the stack.
 * The user must implement the "Display" function, and specify the type of the element to be printed.
 * @param pStack Address of the stack.
 * @param pfDisplay Address of the display function implemented by the user.
 * @return STACK_SUCCESS on success.
 * @return STACK_EMPTY if the stack is empty.
 */
en_Stack_Status TraverseStack(Stack *pStack, void (*pfDisplay) (STACK_ENTRY)) {
    uint8_t i = 0;
    if (pStack->top != STACK_INIT) {
        for (i = pStack->top; i > 0; i--) {
            pfDisplay(pStack->entry[i - 1]);
        }
        return STACK_SUCCESS;
    } else {
        return STACK_EMPTY;
    }
}
