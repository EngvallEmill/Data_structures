/*
 * DV1: Datatyper och datastrukturer
 * Fall 23
 * OU6
 *
 * File:         set-test.c
 * Description:  
 * Author:       Emil Engvall
 * CS username:  ens19esm
 * Date:         2023-12-17
 */

#include <stdio.h>
#include <stdlib.h>
#include "set.h"

void print_test_result(int condition, const char *test_name);
void test_set_empty();
void test_set_single();
void test_set_insert_and_member_of();
void test_set_union();
void test_set_intersection();
void test_set_difference();
void test_set_remove();
void test_set_properties();


int main() 
{
    printf("Running set tests...\n");
    test_set_empty();
    test_set_single();
    test_set_insert_and_member_of();
    test_set_union();
    test_set_intersection();
    test_set_difference();
    test_set_remove();
    test_set_properties();
    
    printf("All tests completed.\n");
    return 0;
}

void print_test_result(int condition, const char *test_name) 
{
    if (condition) {
        printf("PASS: %s\n", test_name);
    } else {
        printf("FAIL: %s\n", test_name);
    }
}

void test_set_empty() 
{
    set *s = set_empty();
    print_test_result(s != NULL && set_is_empty(s), "set_empty");
    set_destroy(s);
}

void test_set_single() 
{
    int value = 10;
    set *s = set_single(value);
    print_test_result(s != NULL && set_member_of(value, s), "set_single");
    set_destroy(s);
}

void test_set_insert_and_member_of() 
{
    set *s = set_empty();
    set_insert(5, s);
    set_insert(10, s);

    int condition = set_member_of(5, s) && set_member_of(10, s) && !set_member_of(3, s);
    print_test_result(condition, "set_insert_and_member_of");

    set_destroy(s);
}

void test_set_union() 
{
    set *s1 = set_single(1);
    set *s2 = set_single(2);
    set *u = set_union(s1, s2);

    int condition = set_member_of(1, u) && set_member_of(2, u);
    print_test_result(condition, "set_union");

    set_destroy(s1);
    set_destroy(s2);
    set_destroy(u);
}

void test_set_intersection() 
{
    set *s1 = set_single(1);
    set_insert(2, s1);
    set *s2 = set_single(2);
    set *i = set_intersection(s1, s2);

    int condition = !set_member_of(1, i) && set_member_of(2, i);
    print_test_result(condition, "set_intersection");

    set_destroy(s1);
    set_destroy(s2);
    set_destroy(i);
}

void test_set_difference() 
{
    set *s1 = set_single(1);
    set_insert(2, s1);
    set *s2 = set_single(1);
    set *d = set_difference(s1, s2);

    int condition = !set_member_of(1, d) && set_member_of(2, d);
    print_test_result(condition, "set_difference");

    set_destroy(s1);
    set_destroy(s2);
    set_destroy(d);
}

void test_set_remove() 
{
    set *s = set_single(1);
    set_insert(2, s);
    set_remove(1, s);

    int condition = !set_member_of(1, s) && set_member_of(2, s);
    print_test_result(condition, "set_remove");

    set_destroy(s);
}

void test_set_properties() 
{
    set *s1 = set_single(1);
    set *s2 = set_single(1);

    int condition = set_equal(s1, s2) && set_subset(s1, s2);
    print_test_result(condition, "set_properties (equal and subset)");

    set_destroy(s1);
    set_destroy(s2);
}

