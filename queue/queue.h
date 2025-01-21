#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include "list.h"

/**
 * @defgroup queue_h Queue
 * @brief The module is used to manage a queue using a doubly linked list.
 *
 * This module provides functions to create, manipulate, and destroy a
 * queue. It includes capabilities such as enqueueing, dequeueing, and
 * checking if the queue is empty.
 * 
 * Error Handling:
 * All functions in this module report errors using perror. This means that if
 * an error occurs within any function, it will generate an appropriate error
 * message to the standard error output, providing insight into what went wrong.
 * 
 * @author Emil Engvall
 * @since  2023-12-02
 * @{
 */

/**
 *  @brief Defines the structure for a queue.
 */
typedef struct queue
{
    List *list; /**< Pointer to the list used to implement the queue.**/
} Queue;

/**
 * @brief Creates and returns an empty queue.
 *
 * Allocates memory for a new queue and initializes it with an empty list.
 * It is the caller's responsibility to call queue_destroy to free the queue's memory.
 *
 * @return A pointer to the newly created queue.
 */
Queue *queue_create(void);

/**
 * @brief Deallocates a queue and all of its elements.
 *
 * Traverses the queue and deallocates each element. Finally,
 * the queue itself is deallocated.
 *
 * @param q A pointer to the queue to destroy.
 * @return -
 */
void queue_destroy(Queue *q);

/**
 * @brief Adds a new value to the tail of the queue.
 *
 * Allocates memory for the new value and adds it to the end of the queue.
 *
 * @param q A pointer to the queue.
 * @param value The value to add to the queue.
 * @return -
 */
void queue_enqueue(Queue *q, const char *value);

/**
 * @brief Removes and returns the value at the head of the queue.
 *
 * Removes the value from the front of the queue and returns it. The caller
 * is responsible for deallocating the returned string.
 *
 * @param q A pointer to the queue.
 * @return A pointer to the value removed from the queue.
 */
char *queue_dequeue(Queue *q);

/**
 * @brief Checks if the queue is empty.
 *
 * Determines if the queue contains no elements.
 *
 * @param q A pointer to the queue.
 * @return true if the queue is empty, false otherwise.
 */
bool queue_is_empty(const Queue *q);

#endif /* QUEUE_H */
/**
 * @}
 */
