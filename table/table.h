#ifndef TABLE_H
#define TABLE_H

#include <stdbool.h>

/**
 * @defgroup table_h Hash Table
 *
 * @brief The module is used to manage a hash table.
 *
 * This module provides functions to create, manipulate, and destroy a
 * hash table. It includes capabilities such as insertion, lookup, and deletion
 * of key-value pairs.
 *
 *
 * @author Emil Engvall
 * @since  2023-11-26
 * @{
 */

/**
 * @brief This structure represents a bucket in the hash table.
 */
struct bucket
{
    int key;   /**< The key of the bucket. **/
    int value; /**< The value associated with the key. **/
    bool used; /**< Flag to indicate if the bucket is used. **/
};

/**
 * @brief Defines the structure for a hash table.
 */
typedef struct table
{
    int capacity;            /**< The number of buckets in the table. **/
    struct bucket *buckets;  /**< Array of buckets. **/
} Table;

/**
 * @brief Creates and returns an empty hash table with a given capacity.
 *
 * Allocates memory for a new hash table and initializes it with the specified
 * capacity. The caller is responsible for calling table_destroy to free the
 * table's memory.
 *
 * @param capacity The number of buckets in the table.
 * @return A pointer to the newly created table.
 */
Table *table_create(int capacity);

/**
 * @brief Deallocates a hash table and all of its elements.
 *
 * Frees the memory allocated for the table and its buckets.
 *
 * @param tab A pointer to the table to destroy.
 * @return -
 */
void table_destroy(Table *tab);

/**
 * @brief Looks up a value by its key in the table.
 *
 * Searches for the key in the table and, if found, stores the associated
 * value in the provided pointer.
 *
 * @param tab The table to search.
 * @param key The key to search for.
 * @param value Pointer to store the value if found.
 * @return true if the key was found, false otherwise.
 */
bool table_lookup(Table *tab, int key, int *value);

/**
 * @brief Inserts a key/value pair into the table, overwriting if the key exists.
 *
 * Inserts or updates the key-value pair in the table.
 *
 * @param tab The table to insert into.
 * @param key The key to insert.
 * @param value The value associated with the key.
 * @return -
 */
void table_insert(Table *tab, int key, int value);

#endif /* TABLE_H */
/**
 * @}
 */
