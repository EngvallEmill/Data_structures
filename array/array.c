/**
 * @file array.c
 * @brief Implementation of a two-dimensional dynamic array.
 *
 * This file provides functionality for creating, managing, and manipulating
 * a two-dimensional dynamic array. It includes functions to create and destroy
 * the array, access and modify elements, and retrieve the number of rows and columns.
 * Error handling is implemented for invalid operations such as accessing out-of-bounds
 * elements or operating on null pointers.
 *
 * @author Emil Engvall
 * @date 2023-11-19
 */

#include <stdio.h>
#include <stdlib.h>
#include "array.h"

Array *array_create(int n1, int n2) 
{
    Array *arr = (Array *)malloc(sizeof(Array));
    if (arr == NULL) {
        perror("Error allocating Array");
        return NULL;
    }

    arr->n1 = n1;
    arr->n2 = n2;
    arr->data = (int *)calloc(n1 * n2, sizeof(int));
    if (arr->data == NULL) {
        free(arr);
        perror("Error allocating Array data");
        return NULL;
    }

    return arr;
}

void array_destroy(Array *arr) 
{
    if (arr != NULL) {
        free(arr->data);
        free(arr);
    } else {
        perror("Attempt to free a null pointer in array_destroy");
    }
}

int array_rows(const Array *arr) 
{
    if (arr != NULL) {
        return arr->n1;
    } else {
        perror("Null pointer received by array_rows");
        return 0;
    }
}

int array_columns(const Array *arr) 
{
    if (arr != NULL) {
        return arr->n2;
    } else {
        perror("Null pointer received by array_columns");
        return 0;
    }
}

int array_get(const Array *arr, int i1, int i2) 
{
    if (arr == NULL || i1 < 0 || i1 >= arr->n1 || i2 < 0 || i2 >= arr->n2) {
        perror("Invalid index or null pointer in array_get");
        return 0; 
    }
    return arr->data[i1 * arr->n2 + i2];
}

void array_set(Array *arr, int i1, int i2, int value) 
{
    if (arr != NULL && i1 >= 0 && i1 < arr->n1 && i2 >= 0 && i2 < arr->n2) {
        arr->data[i1 * arr->n2 + i2] = value;
    } else {
        perror("Invalid index or null pointer in array_set");
    }
}
