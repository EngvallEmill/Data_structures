#ifndef BS_TREE_H
#define BS_TREE_H

#include <stdbool.h>

/**
 * @defgroup bs_tree_h Binary Search Tree
 * @brief This module is used for managing a binary search tree.
 *
 * The module provides functions for creating a binary search tree and
 * managing its nodes. It includes operations such as insertion, inspection,
 * and destruction of the tree and its nodes.
 *
 * Note on Memory Management:
 * Functions in this module dynamically allocate memory for tree nodes.
 * It is the responsibility of the user to ensure that this memory is
 * properly deallocated using bs_tree_destroy to avoid memory leaks.
 *
 * Error Handling:
 * Functions without perror messeges assume successful execution.
 * All functions returns perror messeges on fail.
 *
 * @author Emil Engvall
 * @since  2023-12-20
 * @{
 */

/**
 * @brief Node structure for the binary search tree.
 */
struct node {
    int value;                /**< The value of the node. **/
    struct node *left_child;  /**< Pointer to the left child. **/
    struct node *right_child; /**< Pointer to the right child. **/
};

typedef struct node BSTree;
typedef struct node* BSTreePos;

/**
 * @brief Creates a binary search tree node with a given value.
 *
 * @param value The value to store in the node.
 * @return A pointer to the newly created node or NULL in case of memory allocation failure.
 */
BSTree *bs_tree_make(int value);

/**
 * @brief Inserts a new node as the left child of the specified position.
 * If a left child already exists at the given position, the function
 * will fail and return NULL.
 *
 * @param value The value for the new node.
 * @param pos The position where the left child will be inserted.
 * @return The position of the newly inserted left child or NULL if
 * a child already exists.
 */
BSTreePos bs_tree_insert_left(int value, BSTreePos pos);

/**
 * @brief Inserts a new node as the right child of the specified position.
 * If a right child already exists at the given position, the function
 * will fail and return NULL.
 *
 * @param value The value for the new node.
 * @param pos The position where the right child will be inserted.
 * @return The position of the newly inserted right child or NULL if
 * a child already exists.
 */
BSTreePos bs_tree_insert_right(int value, BSTreePos pos);

/**
 * @brief Retrieves the value of the node at a given position.
 *
 * @param pos The position of the node to inspect.
 * @return The value of the node.
 */
int bs_tree_inspect_label(BSTreePos pos);

/**
 * @brief Checks if a node has a left child.
 *
 * @param pos The position of the node to check.
 * @return true if the node has a left child, false otherwise.
 */
bool bs_tree_has_left_child(BSTreePos pos);

/**
 * @brief Checks if a node has a right child.
 *
 * @param pos The position of the node to check.
 * @return true if the node has a right child, false otherwise.
 */
bool bs_tree_has_right_child(BSTreePos pos);

/**
 * @brief Retrieves the root of the binary search tree.
 *
 * @param tree The binary search tree.
 * @return The position of the root node.
 */
BSTreePos bs_tree_root(BSTree *tree);

/**
 * @brief Retrieves the left child of a node.
 *
 * @param pos The position of the node.
 * @return The position of the left child.
 */
BSTreePos bs_tree_left_child(BSTreePos pos);

/**
 * @brief Retrieves the right child of a node.
 *
 * @param pos The position of the node.
 * @return The position of the right child.
 */
BSTreePos bs_tree_right_child(BSTreePos pos);

/**
 * @brief Destroys the binary search tree, freeing all allocated resources.
 *
 * @param tree The binary search tree to destroy.
 */
void bs_tree_destroy(BSTree *tree);

#endif /* BS_TREE_H */
/**
 * @}
 */
