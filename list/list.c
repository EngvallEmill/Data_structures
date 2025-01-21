/**
 * @file list.c
 * @brief Implementation of a doubly linked list.
 *
 * Provides basic operations for a doubly linked list such as creating,
 * destroying, checking if it's empty, getting the first and last positions,
 * inserting, removing, and getting values at specific positions.
 *
 * @author Emil Engvall
 * @date 2023-11-08
 */

#include "list.h"
#include <stdlib.h>
#include <string.h>

/* Declaration of internal functions */
static char *clone_string(const char *in);
static struct node *make_node(const char *value);


/* ---------------------- Internal functions ---------------------- */

/**
 * @brief Clones a string.
 *
 * Allocates memory for a new string and copies the content from the input string.
 *
 * @param[in] in The input string to clone.
 * @return A pointer to the cloned string.
 */
static char *clone_string(const char *in)
{
    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));

    strncpy(out, in, len);
    
    return out;
}


/**
 * @brief Creates a new node for the list.
 *
 * Allocates memory for a new node and sets its value to the cloned input string.
 *
 * @param[in] value The value to assign to the node.
 * @return A pointer to the created node.
 */
static struct node *make_node(const char *value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->value = clone_string(value);
    return new_node;
}


/* ---------------------- External functions ---------------------- */

List *list_create(void) {
    List *lst = malloc(sizeof(List));
    if (lst != NULL) {
        lst->head.next = &lst->head;
        lst->head.prev = &lst->head;
        lst->head.value = NULL;
    }
    return lst;
}


void list_destroy(List *lst) {
    if (lst != NULL) {
        struct node *current = lst->head.next;
        while (current != &lst->head) {
            struct node *next = current->next;
            free(current->value);
            free(current);
            current = next;
        }
        free(lst);
    }
}


bool list_is_empty(const List *lst) {
    return lst->head.next == &lst->head;
}


ListPos list_first(List *lst) {
    ListPos pos = {
        .node = lst->head.next
    };

    return pos; 
}


ListPos list_end(List *lst) {
    ListPos pos = {
        .node = &lst->head
    };

    return pos;
}


bool list_pos_equal(ListPos p1, ListPos p2) {
    return p1.node == p2.node;
}


ListPos list_next(ListPos pos) {
    ListPos next_pos;
    next_pos.node = pos.node->next;
    return next_pos;
}


ListPos list_prev(ListPos pos) {
    ListPos prev_pos;
    prev_pos.node = pos.node->prev;
    return prev_pos;
}


ListPos list_insert(ListPos pos, const char *value) {
    // Create a new node.
    struct node *node = make_node(value);

    // Find nodes before and after (may be the same node: the head of the list).
    struct node *before = pos.node->prev;
    struct node *after = pos.node;

    // Link to node after.
    node->next = after;
    after->prev = node;

    // Link to node before.
    node->prev = before;
    before->next = node;

    // Return the position of the new element.
    pos.node = node;
    return pos;
}


ListPos list_remove(ListPos pos) {
    if (pos.node->value != NULL) { 
        pos.node->prev->next = pos.node->next;
        pos.node->next->prev = pos.node->prev;
        ListPos next_pos = {pos.node->next};
        free(pos.node->value);
        free(pos.node);
        return next_pos;
    }
    return pos;
}

const char *list_inspect(ListPos pos) {
    return pos.node->value;
}
