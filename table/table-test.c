/*
 * DV1:Datatyper och datastrukturer (5DV224)
 * HT23
 * Assignment:   ou3
 * 
 * Description:  This program tests the functionality of a custom hash table in C.
 *               It inserts specific key/value pairs, verifies their presence, 
 *               and checks for the absence of non-inserted keys.
 * 
 * File:         table-test.c
 * Author:       Emil Engvall
 * CS username:  ens19esm
 * Date:         26-11-2023
 */

#include <stdio.h>
#include "table.h"

int main(void) {
    // Create an empty table
    Table *tab = table_create(100);

    // Add key/value pairs
    for (int n = 51; n <= 60; n++) {
        table_insert(tab, n, -n);
    }
    for (int n = 141; n <= 160; n++) {
        table_insert(tab, n, n*n);
    }

    // Test the presence of added pairs
    bool test1 = true;
    for (int n = 51; n <= 60; n++) {
        int value;
        if (!table_lookup(tab, n, &value) || value != -n) {
            test1 = false;
        }
    }
    for (int n = 141; n <= 160; n++) {
        int value;
        if (!table_lookup(tab, n, &value) || value != n*n) {
            test1 = false;
        }
    }
    printf("Test the presence of added key/value pairs ... %s\n", test1 ? "PASS" : "FAIL");

    // Test the absence of non-added keys
    bool test2 = true;
    for (int n = 1; n <= 200; n++) {
        if ((n < 51 || (n > 60 && n < 141) || n > 160) && table_lookup(tab, n, NULL)) {
            test2 = false;
        }
    }
    printf("Test the absence of non-added keys ... %s\n", test2 ? "PASS" : "FAIL");

    table_destroy(tab);

    return 0;
}
