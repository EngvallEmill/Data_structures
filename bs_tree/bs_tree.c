/**
 * file bs_tree.c
 * This module is used for managing a binary search tree.
 *
 * The module provides functions for creating a binary search tree and
 * managing its nodes. It includes operations such as insertion, inspection,
 * and destruction of the tree and its nodes.
 * 
 * author Emil Engvall
 * date  2023-12-20
 * 
 */

#include "bs_tree.h"
#include <stdlib.h>
#include <stdio.h>

/* ---------------------- Internal functions ---------------------- */

/**
 * Recursively frees a BST node and its children.
 *
 * This internal function is called for deallocating a node and its
 * child nodes in the tree, used primarily by bs_tree_destroy.
 *
 * The BST node to be destroyed.
 */
void destroy_node(BSTree *node) 
{
    if (node != NULL) {
        destroy_node(node->left_child);
        destroy_node(node->right_child);
        free(node);
    }
}

/* ---------------------- External functions ---------------------- */

BSTree *bs_tree_make(int value) 
{
    BSTree *new_tree = (BSTree *)malloc(sizeof(BSTree));
    if (new_tree == NULL) {
        perror("Error in bs_tree_make: Memory allocation failed");
        return NULL;
    }
    new_tree->value = value;
    new_tree->left_child = NULL;
    new_tree->right_child = NULL;
    return new_tree;
}

BSTreePos bs_tree_insert_left(int value, BSTreePos pos) 
{
    if (pos == NULL) {
        perror("Error in bs_tree_insert_left: Null position received");
        return NULL;
    }
    if (pos->left_child != NULL) {
        perror("Error in bs_tree_insert_left: Left child already exists");
        return NULL;
    }
    BSTreePos new_node = (BSTreePos)malloc(sizeof(struct node));
    if (new_node == NULL) {
        perror("Error in bs_tree_insert_left: Memory allocation failed");
        return NULL;
    }
    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    pos->left_child = new_node;
    return new_node;
}

BSTreePos bs_tree_insert_right(int value, BSTreePos pos) 
{
    if (pos == NULL) {
        perror("Error in bs_tree_insert_right: Null position received");
        return NULL;
    }
    if (pos->right_child != NULL) {
        perror("Error in bs_tree_insert_right: Right child already exists");
        return NULL;
    }
    BSTreePos new_node = (BSTreePos)malloc(sizeof(struct node));
    if (new_node == NULL) {
        perror("Error in bs_tree_insert_right: Memory allocation failed");
        return NULL;
    }
    new_node->value = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    pos->right_child = new_node;
    return new_node;
}

int bs_tree_inspect_label(BSTreePos pos) 
{
    if (pos == NULL) {
        perror("Error in bs_tree_inspect_label: Null position received");
        return 1;
    }
    return pos->value;
}

bool bs_tree_has_left_child(BSTreePos pos) 
{
    if (pos == NULL) {
        perror("Error in bs_tree_has_left_child: Null position received");
        return false;
    }
    return pos->left_child != NULL;
}

bool bs_tree_has_right_child(BSTreePos pos) 
{
    if (pos == NULL) {
        perror("Error in bs_tree_has_right_child: Null position received");
        return false;
    }
    return pos->right_child != NULL;
}

BSTreePos bs_tree_root(BSTree *tree) 
{
    if (tree == NULL) {
        perror("Error in bs_tree_root: Null tree received");
        return NULL;
    }
    return tree;
}

BSTreePos bs_tree_left_child(BSTreePos pos) 
{
    if (pos == NULL) {
        perror("Error in bs_tree_left_child: Null position received");
        return NULL;
    }
    return pos->left_child;
}

BSTreePos bs_tree_right_child(BSTreePos pos) 
{
    if (pos == NULL) {
        perror("Error in bs_tree_right_child: Null position received");
        return NULL;
    }
    return pos->right_child;
}

void bs_tree_destroy(BSTree *tree) 
{
    if (tree == NULL) {
        perror("Error in bs_tree_destroy: Null tree received");
        return;
    }
    destroy_node(tree);
}
