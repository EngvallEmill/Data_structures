#ifndef SET_H
#define SET_H

#include <stdbool.h>

/**
 * @defgroup set_h Set Operations
 * @brief This module is used for managing a set of integers.
 *
 * The module provides functions for creating and manipulating sets of integers.
 * It includes operations for set creation, modification, and querying.
 *
 * Error Handling:
 * Functions without perror messeges assume successful execution.
 * All functions returns perror messeges on fail.
 *
 * @author Emil Engvall
 * @since  2023-12-17
 * @{
 */

/**
 * @brief Set the type for the set.
 */
typedef struct set set;

/**
 * @brief Creates a new empty set.
 * 
 * @return A pointer to the newly created empty set.
 */
set *set_empty();

/**
 * @brief Creates a new set with a single member.
 * 
 * @param value The integer value to be the single member of the set.
 * @return A pointer to the newly created set.
 */
set *set_single(const int value);

/**
 * @brief Inserts a value into the set.
 * 
 * @param value The integer value to be inserted.
 * @param s The set where the value will be inserted.
 */
void set_insert(const int value, set *s);

/**
 * @brief Returns a new set that is the union of two sets.
 * 
 * @param s1 The first set.
 * @param s2 The second set.
 * @return A pointer to the new set that represents the union of s1 and s2.
 */
set *set_union(const set *const s1, const set *const s2);

/**
 * @brief Returns a new set that is the intersection of two sets.
 * 
 * @param s1 The first set.
 * @param s2 The second set.
 * @return A pointer to the new set that represents the intersection of s1 and s2.
 */
set *set_intersection(const set *const s1, const set *const s2);

/**
 * @brief Returns a new set that is the difference of two sets (s1 \ s2).
 * 
 * @param s1 The first set.
 * @param s2 The second set.
 * @return A pointer to the new set that represents the difference of s1 and s2.
 */
set *set_difference(const set *const s1, const set *const s2);

/**
 * @brief Checks if the set is empty.
 * 
 * @param s The set to check.
 * @return true if the set is empty, false otherwise.
 */
bool set_is_empty(const set *const s);

/**
 * @brief Checks if a value is a member of the set.
 * 
 * @param value The value to check.
 * @param s The set to check in.
 * @return true if the value is a member of the set, false otherwise.
 */
bool set_member_of(const int value, const set *const s);

/**
 * @brief Returns a random member of the set.
 * 
 * @param s The set to choose from.
 * @return An integer representing a random member of the set.
 */
int set_choose(const set *const s);

/**
 * @brief Removes a value from the set.
 * 
 * @param value The value to remove.
 * @param s The set to remove the value from.
 */
void set_remove(const int value, set *const s);

/**
 * @brief Checks if two sets are equal.
 * 
 * @param s1 The first set.
 * @param s2 The second set.
 * @return true if the sets are equal, false otherwise.
 */
bool set_equal(const set *const s1, const set *const s2);

/**
 * @brief Checks if the first set is a subset of the second set.
 * 
 * @param s1 The first set.
 * @param s2 The second set.
 * @return true if s1 is a subset of s2, false otherwise.
 */
bool set_subset(const set *const s1, const set *const s2);

/**
 * @brief Returns an array containing all values in the set.
 * 
 * @param s The set.
 * @return An array of integers representing the values in the set.
 */
int *set_get_values(const set *const s);

/**
 * @brief Returns the number of elements in the set.
 * 
 * @param s The set.
 * @return The number of elements in the set.
 */
int set_size(const set *const s);

/**
 * @brief Destroys the set, freeing all allocated resources.
 * 
 * @param s The set to destroy.
 */
void set_destroy(set *s);

#endif /* SET_H */
/**
 * @}
 */
