//
// Created by khaled on 9/13/23.
//

#include <stdlib.h>
#include "linked_list_stack.h"

/**
 * Pushes an element to the top of the stack.
 * @param element The element to be pushed onto the stack.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 * @return STACK_OVERFLOW if the stack is full.
 */
en_Stack_Status Push(STACK_ENTRY element, Stack *pStack) {
    StackNode *pTmp = malloc(sizeof(StackNode));
    pTmp->content = element;
    pTmp->pNext = pStack->pTop;
    pStack->pTop = pTmp;
    pStack->stack_size++;
    return STACK_SUCCESS;
}

/**
 * Pops out the top element from the stack.
 * @param pElement Address of the element to store the popped element.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 * @return STACK_UNDERFLOW if the stack is empty.
 */
en_Stack_Status Pop(STACK_ENTRY *pElement, Stack *pStack) {
    if (pStack->pTop != NULL) {
        StackNode *pTmp = pStack->pTop;
        *pElement = pTmp->content;
        pStack->pTop = pTmp->pNext;
        free(pTmp);
        pStack->stack_size--;
        return STACK_SUCCESS;
    } else {
        return STACK_UNDERFLOW;
    }
}

/**
 * Checks if the stack is empty.
 * @param pStack Address of the stack.
 * @return STACK_EMPTY if stack is empty.
 * @return STACK_ERROR on failure.
 */
en_Stack_Status StackEmpty(Stack *pStack) {
    if (pStack->pTop == NULL) {
        return STACK_EMPTY;
    } else {
        return STACK_ERROR;
    }
}

/**
 * @brief Checks if the stack is full.
 * In the linked-list implementation this function shall never return true.
 * @param pStack Address of the stack.
 * @return STACK_ERROR on failure.
 */
en_Stack_Status StackFull(Stack *pStack) {
    return STACK_ERROR;
}

/**
 * Initializes the top of the stack to the initial value.
 * @param pStack Address of the stack.
 * @return STACK_INITIALIZED on success.
 */
en_Stack_Status StackInit(Stack *pStack) {
    pStack->pTop = NULL;
    pStack->stack_size = 0;
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
    if (pStack->pTop == NULL) {
        return STACK_UNDERFLOW;
    } else {
        *pElement = pStack->pTop->content;
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
    *pSize = pStack->stack_size;
    return STACK_SUCCESS;
}

/**
 * Clears the stack.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 */
en_Stack_Status ClearStack(Stack *pStack) {
    StackNode *pTmp = pStack->pTop;
    while (pTmp != NULL) {
        pStack->pTop = pTmp->pNext;
        free(pTmp);
        pTmp = pStack->pTop;
    }
    return STACK_CLEAR_SUCCESS;
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
    StackNode *pTmp = pStack->pTop;
    if (pStack->pTop != NULL) {
        while (pTmp != NULL) {
            pfDisplay(pTmp->content);
            pTmp = pTmp->pNext;
        }
        return STACK_SUCCESS;
    } else {
        return STACK_EMPTY;
    }
}
