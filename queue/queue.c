/**
 * @file queue.c
 * @brief The module is used to manage a queue using a doubly linked list.
 *
 * This module provides functions to create, manipulate, and destroy a
 * queue. It includes capabilities such as enqueueing, dequeueing, and
 * checking if the queue is empty.
 * 
 * @author Emil Engvall
 * @date  2023-12-02
 * @{
 */

#include "queue.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
    if (in == NULL) {
        perror("Error in clone_string: Input string is NULL");
        return NULL;
    }

    size_t len = strlen(in);
    char *out = calloc(len + 1, sizeof(char));

    if (out == NULL) {
        perror("Error in clone_string: Memory allocation failed for output string");
        return NULL;
    }

    strncpy(out, in, len);
    
    return out;
}

/* ---------------------- External functions ---------------------- */

Queue *queue_create(void) 
{
    Queue *q = malloc(sizeof(Queue));
    if (!q) {
        perror("Error in queue_create: Memory allocation failed");
        return NULL;
    }
    q->list = list_create();
    if (!q->list) {
        perror("Error in queue_create: List creation failed");
        free(q);
        return NULL;
    }
    return q;
}

void queue_destroy(Queue *q) 
{
    if (!q) {
        perror("Error in queue_destroy: Null pointer received");
        return;
    }
    list_destroy(q->list);
    free(q);
}

void queue_enqueue(Queue *q, const char *value) 
{
    if (!q || !value) {
        perror("Error in queue_enqueue: Null pointer received");
        return;
    }
    list_insert(list_end(q->list), value);
}

char *queue_dequeue(Queue *q) 
{
    if (!q) {
        perror("Error in queue_dequeue: Null pointer received");
        return NULL;
    }
    if (list_is_empty(q->list)) {
        perror("Error in queue_dequeue: Queue is empty");
        return NULL;
    }
    ListPos pos = list_first(q->list);
    char *value = clone_string(list_inspect(pos));
    if (!value) {
        perror("Error in queue_dequeue: clone_string failed");
        return NULL;
    }
    list_remove(pos);
    return value;
}

bool queue_is_empty(const Queue *q) 
{
    if (!q) {
        perror("Error in queue_is_empty: Null pointer received");
        return true;
    }
    return list_is_empty(q->list);
}