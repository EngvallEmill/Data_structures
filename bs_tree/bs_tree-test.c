#include "bs_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


// Declarations of functions.
void print_array(int n, int a[]);
void swap(int *a, int *b);
void insert_value(int value, BSTreePos first_pos);
BSTreePos search_value(int value, BSTreePos first_pos);


int main(void)
{
    // Create an array with the values 1, 2, ..., 10 and print out the content.
    int n = 10;
    int arr[n];

    srand(time(0));

    for (int i = 0 ; i < n ; i++) {
        arr[i] = i + 1;
    }

    print_array(n, arr);

    // Shuffle the values in the array and print out the content.
    for (int i = n - 1 ; i > 0 ; i--) {
        int j = rand() % i;
        swap(&arr[j], &arr[i]);
    }

    print_array(n, arr);

    // Create a binary search tree and insert the values in the array.
    BSTree *tree = bs_tree_make(arr[0]);
    for (int i = 1 ; i < n ; i++) {
        BSTreePos pos = bs_tree_root(tree);
        insert_value(arr[i], pos);
    }

    // Search the binary search tree for each of the values in the array and
    // print out the result of the search.
    for (int i = 0 ; i < n ; i++) {
        BSTreePos pos = bs_tree_root(tree);
        if (search_value(arr[i], pos) == NULL) {
            printf("Value %d not found\n", arr[i]);
        } else {
            printf("Value %d found\n", arr[i]);
        }
    }

    // Search the binary search tree for a value that is not in the array and
    // print out the result of the search.
    BSTreePos pos = bs_tree_root(tree);
    int x = 99;
    if (search_value(x, pos) == NULL) {
        printf("Value %d not found\n", x);
    } else {
        printf("Value %d found\n", x);
    }

    // Destroy the binary search tree.
    bs_tree_destroy(tree);

    return 0;
}


// Print the array.
void print_array(int n, int a[])
{
    printf("Array: ");
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}


// Swap the values.
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


// Insert a value in the tree.
void insert_value(int value, BSTreePos pos)
{
    if (pos == NULL) {
        perror("Attempted to insert into a NULL position.\n");
        return;
    }

    BSTreePos parent = NULL;

    while (pos != NULL) {
        parent = pos;
        if (value < pos->value) {
            pos = pos->left_child;
        } else if (value > pos->value) {
            pos = pos->right_child;
        } else {
            return;
        }
    }
    
    BSTreePos newNode = bs_tree_make(value);
    if (value < parent->value) {
        parent->left_child = newNode;
    } else {
        parent->right_child = newNode;
    }
}


// Search for a value in the tree.
BSTreePos search_value(int value, BSTreePos pos)
{
    while (pos != NULL) {
        if (value < pos->value) {
            pos = pos->left_child;
        } else if (value > pos->value) {
            pos = pos->right_child;
        } else {
            return pos;
        }
    }
    return NULL;
}