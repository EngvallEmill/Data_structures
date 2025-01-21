#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

/**
 * @defgroup list_h Doubly Linked List
 *
 * @brief The module is used to manage a doubly linked list.
 *
 * This module provides functions to create, manipulate, and destroy a
 * doubly linked list. It includes capabilities such as insertion, deletion,
 * and traversal.
 *
 * As this is an educational example, certain functionalities may be absent
 * or incomplete. The module serves as a demonstration of design considerations
 * for a linked list data structure.
 *
 * @author Emil Engvall
 * @since  2023-11-08
 * @{
 */


/**
 *  @brief This structure represents a node in the list.
 */
struct node
{
    struct node *next; /**< Pointer to the next node.**/
    struct node *prev; /**< Pointer to the previous node.**/
    char *value;       /**< Pointer to the value stored in the node.**/
};

/**
 *  @brief Defines the structure for a list.
 */
typedef struct list
{
    struct node head;  /**< Sentinel node acting as the list head.**/    
} List;


/**
 *  @brief This structure represents a position within the list.
 */
typedef struct list_pos
{
    struct node *node; /**< Pointer to the current node at this position.**/
} ListPos;

/**
 * @brief Creates and returns an empty list.
 *
 * Allocates memory for a new list and initializes it. It is the caller's
 * responsibility to call list_destroy to free the list's memory.
 *
 * @return A pointer to the newly created list.
 */
List *list_create(void);

/**
 * @brief Deallocates a list and all of its elements.
 *
 * Traverses the list and deallocates each node and its value. Finally,
 * the list itself is deallocated.
 *
 * @param lst A pointer to the list to destroy.
 * @return -
 */
void list_destroy(List *lst);

/**
 * @brief Checks if the list is empty.
 *
 * Determines if the list contains no elements.
 *
 * @param lst A pointer to the list.
 * @return true if the list is empty, false otherwise.
 */
bool list_is_empty(const List *lst);

/**
 * @brief Retrieves the position of the first element in the list.
 *
 * @param lst A pointer to the list.
 * @return The position of the first element.
 */
ListPos list_first(List *lst);

/**
 * @brief Retrieves the position after the last element in the list.
 *
 * @param lst A pointer to the list.
 * @return The position after the last element.
 */
ListPos list_end(List *lst);

/**
 * @brief Checks if two positions in the list are equal.
 *
 * @param p1 The first position to compare.
 * @param p2 The second position to compare.
 * @return true if the positions are the same, false otherwise.
 */
bool list_pos_equal(ListPos p1, ListPos p2);

/**
 * @brief Moves the position forward in the list.
 *
 * @param pos The current position.
 * @return The next position in the list.
 */
ListPos list_next(ListPos pos);

/**
 * @brief Moves the position backward in the list.
 *
 * @param pos The current position.
 * @return The previous position in the list.
 */
ListPos list_prev(ListPos pos);

/**
 * @brief Inserts a new value before the given position.
 *
 * Allocates a new node, sets its value, and inserts it before the position.
 *
 * @param pos The position before which the new value will be inserted.
 * @param value The value to insert.
 * @return The position of the newly inserted element.
 */
ListPos list_insert(ListPos pos, const char *value);

/**
 * @brief Removes an element at the given position.
 *
 * Deallocates the node at the given position and links its previous
 * and next nodes together.
 *
 * @param pos The position of the element to remove.
 * @return The position of the next element in the list.
 */
ListPos list_remove(ListPos pos);

/**
 * @brief Retrieves the value at the given list position.
 *
 * @param pos The position of the element.
 * @return The value of the element at the given position.
 */
const char *list_inspect(ListPos pos);

#endif /* LIST_H */
/**
 * @}
 */

