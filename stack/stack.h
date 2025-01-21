#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

/**
 * @defgroup stack_h Stack
 * @brief The module is used to manage a stack using dynamic memory allocation.
 *
 * This module provides functions to create, manipulate, and destroy a
 * stack. It includes typical stack operations such as pushing, popping, and
 * checking if the stack is empty. The stack's capacity is dynamically adjusted
 * as needed.
 * 
 * Error Handling:
 * Functions in this module return specific values to indicate success or failure,
 * especially in memory allocation operations.
 * 
 * @author Emil Engvall
 * @since  2023-12-02
 * @{
 */

/**
 * @brief Defines the structure for a stack.
 * 
 * This structure represents a stack with dynamic capacity. The stack supports
 * typical stack operations such as push and pop.
 */
typedef struct stack
{
    int capacity;    /**< The current capacity of the stack. **/
    int size;        /**< The current number of elements in the stack. **/
    double *data;    /**< Pointer to the dynamically allocated array of elements. **/
} Stack;

/**
 * @brief Creates and returns a new empty stack.
 *
 * Allocates memory for a new stack and initializes its capacity and size.
 * Returns NULL if memory allocation fails.
 *
 * @return A pointer to the newly created stack, or NULL if allocation fails.
 */
Stack *stack_create(void);

/**
 * @brief Destroys the stack, freeing all allocated resources.
 *
 * Deallocates the memory used for the stack's elements and then the stack
 * itself.
 *
 * @param s A pointer to the stack to destroy.
 * @return -
 */
void stack_destroy(Stack *s);

/**
 * @brief Pushes a new value onto the stack.
 *
 * Adds a new value to the top of the stack. If the stack is full, its
 * capacity is automatically doubled. The function returns true if the
 * push is successful, false otherwise.
 *
 * @param s A pointer to the stack.
 * @param value The value to push onto the stack.
 * @return -
 */
void stack_push(Stack *s, double value);

/**
 * @brief Pops and returns the top value from the stack.
 *
 * Removes and returns the value from the top of the stack. If the stack
 * is empty, the behavior is undefined.
 *
 * @param s A pointer to the stack.
 * @return The value popped from the stack.
 */
double stack_pop(Stack *s);

/**
 * @brief Checks if the stack is empty.
 *
 * Determines if the stack contains no elements.
 *
 * @param s A pointer to the stack.
 * @return true if the stack is empty, false otherwise.
 */
bool stack_is_empty(const Stack *s);

#endif /* STACK_H */
/**
 * @}
 */
