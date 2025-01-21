/*
 * DV1: Datatyper och datastrukturer
 * Fall 23
 * OU4
 *
 * File:         stack-test.c
 * Description:  a program to test the stack module.
 * Author:       Emil Engvall
 * CS username:  ens19esm
 * Date:         20-12-2023
 */

#include "stack.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void push_values(Stack *s);

bool pop_and_test(Stack *s);

int main(void) 
{
    Stack *s = stack_create();
  
    push_values(s);

    if (pop_and_test(s)) {
        printf("Test the functioning of the stack ... PASS\n");
    } else {
        printf("Test the functioning of the stack ... FAIL\n");
    }

    stack_destroy(s);
    return 0;
}

// Function to push values onto the stack
void push_values(Stack *s) 
{
    for (int n = 1; n <= 10; n++) {
        double value = pow(0.5, n); 
        stack_push(s, value);
    }
}

// Function to pop values from the stack and test their correctness
bool pop_and_test(Stack *s) 
{
    for (int n = 10; n >= 1; n--) {
        double expected = pow(0.5, n);
        double val = stack_pop(s);
        if (val != expected) {
            return false;
        }
    }
    return stack_is_empty(s);
}
