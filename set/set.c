/**
 * File: set.c
 * This module is used for managing a set of integers.
 *
 * The module provides functions for creating and manipulating sets of integers.
 * It includes operations for set creation, modification, and querying.
 * 
 * Author: Emil Engvall
 * Date:  2023-12-17
 * 
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "set.h"

struct set {
    int capacity;
    int size;
    char *array;
};



set *set_empty() 
{
    set *s = malloc(sizeof(set));
    if (s == NULL) {
        perror("Error in set_empty: Allocation failed");
        return NULL;
    }
    s->capacity = 8;
    s->size = 0;
    s->array = calloc(s->capacity / 8, sizeof(char));
    if (s->array == NULL) {
        perror("Error in set_empty: Array allocation failed");
        free(s);
        return NULL;
    }
    return s;
}

set *set_single(const int value) 
{
    set *s = set_empty();
    if (s == NULL) {
        perror("Error in set_single: set_empty failed");
        return NULL;
    }
    set_insert(value, s);
    return s;
}

void set_insert(const int value, set *s) 
{     
    if (s == NULL) {
        perror("Error in set_insert: Null set pointer");
        return;
    }

    if (!set_member_of(value, s)) {
        int bit_in_array = value; // To make the code easier to read

        // Increase the capacity if necessary
        if (bit_in_array >= s->capacity) {
            int no_of_bytes = bit_in_array / 8 + 1;
            s->array = realloc(s->array, no_of_bytes);
            for (int i = s->capacity / 8 ; i < no_of_bytes ; i++) {
                s->array[i] = 0;
            }
            s->capacity = no_of_bytes * 8;
        }

        // Set the bit
        int byte_no = bit_in_array / 8;
        int bit = 7 - bit_in_array % 8;
        s->array[byte_no] = s->array[byte_no] | 1 << bit;
        s->size++;
    }
}

set *set_union(const set *const s1, const set *const s2) 
{
    if (s1 == NULL || s2 == NULL) {
        perror("Error in set_union: Null set pointer");
        return NULL;
    }

    set *s = set_empty();

    for (int i = 0 ; i < s1->capacity || i < s2->capacity ; i++) {
        if (set_member_of(i, s1) || set_member_of(i, s2)) {
            set_insert(i, s);
        }
    }
    return s;
}

set *set_intersection(const set *const s1, const set *const s2) 
{
    if (s1 == NULL || s2 == NULL) {
        perror("Error in set_intersection: Null set pointer");
        return NULL;
    }

    set *s = set_empty();
    if (s == NULL) {
        return NULL;
    }

    for (int i = 0; i < s1->capacity && i < s2->capacity; i++) {
        if (set_member_of(i, s1) && set_member_of(i, s2)) {
            set_insert(i, s);
        }
    }

    return s;
}

set *set_difference(const set *const s1, const set *const s2)
{
    if (s1 == NULL || s2 == NULL) {
        perror("Error in set_difference: Null set pointer");
        return NULL;
    }

    set *s = set_empty();
    if (s == NULL) {
        return NULL;
    }

    for (int i = 0; i < s1->capacity; i++) {
        if (set_member_of(i, s1) && !set_member_of(i, s2)) {
            set_insert(i, s);
        }
    }

    return s;
}

bool set_is_empty(const set *const s) 
{
    if (s == NULL) {
        perror("Error in set_is_empty: Null set pointer");
        return true;
    }

    return s->size == 0;
}

bool set_member_of(const int value, const set *const s) 
{
    if (s == NULL) {
        perror("Error in set_member_of: Null set pointer");
        return false;
    }

    int bit_in_array = value; 

    if (bit_in_array >= s->capacity) {
        return false;
    }

    int byte_no = bit_in_array / 8;
    int bit = 7 - bit_in_array % 8;
    char the_byte = s->array[byte_no];

    return the_byte & 1 << bit;
}

int set_choose(const set *const s) 
{
    if (s == NULL) {
        perror("Error in set_choose: Null set pointer");
        return 0;
    }

    while (true) {
        int rand_index = rand() % s->capacity;
        if (set_member_of(rand_index, s)) {
            return rand_index;
        }
    }
}

void set_remove(const int value, set *const s) 
{
    if (s == NULL) {
        perror("Error in set_member_of: Null set pointer");
        return;
    }

    if (set_member_of(value, s)) {
        int byte_no = value / 8;
        int bit = 7 - value % 8;
        s->array[byte_no] &= ~(1 << bit);
        s->size--;
    }
}

bool set_equal(const set *const s1, const set *const s2) 
{
    if (s1 == NULL || s2 == NULL) {
        perror("Error in set_equal: Null set pointer");
        return false;
    }

    if (s1->size != s2->size) {
        return false;
    }

    for (int i = 0; i < s1->capacity; i++) {
        if (set_member_of(i, s1) != set_member_of(i, s2)) {
            return false;
        }
    }

    return true;
}

bool set_subset(const set *const s1, const set *const s2) 
{
    for (int i = 0; i < s1->capacity; i++) {
        if (set_member_of(i, s1) && !set_member_of(i, s2)) {
            return false;
        }
    }

    return true;
}

int set_size(const set *const s) 
{
    if (s == NULL) {
        perror("Error in set_size: Null set pointer");
        return 0;
    }
    return s->size;
}

int *set_get_values(const set *const s) 
{
    if (s == NULL) {
        perror("Error in set_get_values: Null set pointer");
        return NULL;
    }

    int *values = malloc(s->size * sizeof(int));
    if (values == NULL) {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < s->capacity; i++) {
        if (set_member_of(i, s)) {
            values[j++] = i;
        }
    }

    return values;
}

void set_destroy(set *s) {
    if (s != NULL) {
        free(s->array);
        free(s);
    } else {
        perror("Error in set_destroy: Null pointer received");
    }
}
