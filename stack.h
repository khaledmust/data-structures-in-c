/**
 * @file stack.h
 * @brief API of the array based stack implementation.
 * @author Khaled Mustafa
 * @date 2023/09/10
 * @version 1.0
 */

#ifndef DATA_STRUCTURES_STACK_H
#define DATA_STRUCTURES_STACK_H

#include <stdint.h>

/**
 * @def MAX_STACK Determines the max size of the stack.
 * To be changed according to the user's preference.
 */
#define MAX_STACK 10

/**
 * @def STACK_ENTRY Determines the type of the data to be stored into the stack.
 * To be changed according to the user's preference.
 */
#define STACK_ENTRY uint8_t

/**
 * @struct Stack
 * @var top The top-most value of the stack.
 * @var entry Array of type "STACK_ENTRY" that holds the elements of the stack.
 */
typedef struct stack {
    uint8_t top;
    STACK_ENTRY entry[MAX_STACK];
}Stack;

/**
 * @enum en_Stack_Status The stack API exit status.
 * @var STACK_SUCCESS Operation was successful
 * @var STACK_ERROR Generic error
 * @var STACK_OVERFLOW Stack is full (for Push operation)
 * @var STACK_UNDERFLOW Stack is empty (for Pop and StackTop operations)
 * @var STACK_EMPTY Stack is empty (for StackEmpty function)
 * @var STACK_FULL Stack is full (for StackFull function)
 * @var STACK_INITIALIZED Stack has been initialized (for StackInit function)
 * @var STACK_CLEAR_SUCCESSStack has been successfully cleared (for ClearStack function)
 */
typedef enum {
    STACK_SUCCESS,
    STACK_ERROR,
    STACK_OVERFLOW,
    STACK_UNDERFLOW,
    STACK_EMPTY,
    STACK_FULL,
    STACK_INITIALIZED,
    STACK_CLEAR_SUCCESS
}en_Stack_Status;

/**
 * @brief Pushes an element to the top of the stack.
 * @param element The element to be pushed onto the stack.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 * @return STACK_OVERFLOW if the stack is full.
 */
en_Stack_Status Push(STACK_ENTRY, Stack *);

/**
 * @brief Pops out the top element from the stack.
 * @param pElement Address of the element to store the popped element.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 * @return STACK_UNDERFLOW if the stack is empty.
 */
en_Stack_Status Pop(STACK_ENTRY *, Stack *);

/**
 * @brief Checks if the stack is empty.
 * @param pStack Address of the stack.
 * @return STACK_EMPTY if stack is empty.
 * @return STACK_ERROR on failure.
 */
en_Stack_Status StackEmpty(Stack *);

/**
 * Checks if the stack is full.
 * @param pStack Address of the stack.
 * @return STACK_FULL if the stack is full.
 * @return STACK_ERROR on failure.
 */
en_Stack_Status StackFull(Stack *);

/**
 * Initializes the top of the stack to the initial value.
 * @param pStack Address of the stack.
 * @return STACK_INITIALIZED on success.
 */
en_Stack_Status StackInit(Stack *);

/**
 * Gets the top-most element from the stack.
 * @param pElement Address of the element to store the top-most element value.
 * @param pStack Address of the stack.
 * @return STACK_UNDERFLOW if stack is empty.
 * @return STACK_SUCCESS on success.
 */
en_Stack_Status StackTop(STACK_ENTRY *, Stack *);

/**
 * Gets the size of the stack.
 * @param pStack Address of the stack.
 * @param pSize Address of the variable to store the size to.
 * @return STACK_SUCCESS on success.
 */
en_Stack_Status StackSize(Stack *, uint8_t *);

/**
 * Clears the stack.
 * @param pStack Address of the stack.
 * @return STACK_SUCCESS on success.
 */
en_Stack_Status ClearStack(Stack *);

/**
 * @brief Prints out all the elements of the stack.
 * The user must implement the "Display" function, and specify the type of the element to be printed.
 * @param pStack Address of the stack.
 * @param pfDisplay Address of the display function implemented by the user.
 * @return STACK_SUCCESS on success.
 * @return STACK_EMPTY if the stack is empty.
 */
en_Stack_Status TraverseStack(Stack *, void (*) (STACK_ENTRY));

#endif //DATA_STRUCTURES_STACK_H
