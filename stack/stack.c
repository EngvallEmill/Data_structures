/**
 * @file stack.c
 * @brief The module is used to manage a stack using dynamic memory allocation.
 *
 * This module provides functions to create, manipulate, and destroy a
 * stack. It includes typical stack operations such as pushing, popping, and
 * checking if the stack is empty. The stack's capacity is dynamically adjusted
 * as needed.
 * 
 * @author Emil Engvall
 * @date  2023-12-02
 * @{
 */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

/* ---------------------- Internal functions ---------------------- */

/**
 * @brief Resizes the stack's capacity.
 *
 * Expands or shrinks the stack's memory allocation to the new specified capacity.
 * If memory allocation fails, the function returns false, leaving the stack unchanged.
 *
 * @param[in,out] s The stack to be resized.
 * @param[in] new_capacity The desired new capacity for the stack.
 * @return true if the resizing is successful, false otherwise.
 */
static bool resize_stack(Stack *s, int new_capacity) 
{
    double *new_data = realloc(s->data, new_capacity * sizeof(double));
    if (!new_data) {
        perror("Error in resize_stack: Memory reallocation failed");
        return false;
    }
    s->data = new_data;
    s->capacity = new_capacity;
    return true;
}


/* ---------------------- External functions ---------------------- */

Stack *stack_create(void) 
{
    Stack *s = malloc(sizeof(Stack));
    if (!s) {
        perror("Error in stack_create: Memory allocation failed");
        return NULL;
    }
    s->capacity = 1;
    s->size = 0;
    s->data = malloc(sizeof(double) * s->capacity);
    if (!s->data) {
        perror("Error in stack_create: Memory allocation for data failed");
        free(s);
        return NULL;
    }
    return s;
}

void stack_destroy(Stack *s) 
{
    if (!s) {
        perror("Error in stack_destroy: Null pointer received");
        return;
    }
    free(s->data);
    free(s);
}

void stack_push(Stack *s, double value) 
{
    if (!s) {
        perror("Error in stack_push: Null pointer received");
        return;
    }
    if (s->size == s->capacity) {
        if (!resize_stack(s, s->capacity * 2)) {
            perror("Error in stack_push: Resizing stack failed");
            return;
        }
    }
    s->data[s->size++] = value;
}

double stack_pop(Stack *s) 
{
    if (!s || stack_is_empty(s)) {
        perror("Error in stack_pop: Null pointer received or stack is empty");
        return 0;
    }
    return s->data[--s->size];
}

bool stack_is_empty(const Stack *s) 
{
    if (!s) {
        perror("Error in stack_is_empty: Null pointer received");
        return true; 
    }
    return s->size == 0;
}