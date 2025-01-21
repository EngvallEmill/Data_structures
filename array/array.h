#ifndef ARRAY_H
#define ARRAY_H

/**
 * @defgroup array_h 2D Array
 *
 * @brief The module is used to manage a two-dimensional array.
 *
 * This module provides functions to create, manipulate, and destroy a
 * two-dimensional array implemented as a dynamically allocated one-dimensional
 * array. It includes capabilities such as element access and modification.
 * 
 * Error Handling:
 * All functions in this module report errors using perror. This means that if
 * an error occurs within any function, it will generate an appropriate error
 * message to the standard error output, providing insight into what went wrong.
 *
 * @author Emil Engvall
 * @since  2023-11-26
 * @{
 */

/**
 * @brief Represents a two-dimensional array.
 *
 * This structure defines a two-dimensional array using a dynamically allocated
 * one-dimensional array. It stores the number of rows and columns and a pointer
 * to the array elements.
 */
typedef struct array
{
    int n1;      /**< Number of rows. **/
    int n2;      /**< Number of columns. **/
    int *data;   /**< Pointer to the array elements. **/
} Array;

/**
 * @brief Creates a zero-initialized 2D array.
 *
 * Allocates memory for a new two-dimensional array and initializes all elements
 * to zero. It is the caller's responsibility to call array_destroy to free the
 * array's memory.
 *
 * @param n1 Number of rows.
 * @param n2 Number of columns.
 * @return A pointer to the newly created array.
 */
Array *array_create(int n1, int n2);

/**
 * @brief Deallocates a 2D array.
 *
 * Frees the memory allocated for the array and its elements.
 *
 * @param arr A pointer to the array to destroy.
 * @return -
 */
void array_destroy(Array *arr);

/**
 * @brief Gets the number of rows in the array.
 *
 * @param arr A pointer to the array.
 * @return The number of rows in the array.
 */
int array_rows(const Array *arr);

/**
 * @brief Gets the number of columns in the array.
 *
 * @param arr A pointer to the array.
 * @return The number of columns in the array.
 */
int array_columns(const Array *arr);

/**
 * @brief Retrieves the value at a specified position in the array.
 * 
 * If the specified indices are out of bounds, the behavior is undefined.
 * Users should ensure that indices are within the range of the array dimensions.
 * If the element at the specified position has not been initialized using array_set,
 * the returned value is undefined and should not be relied upon.
 *
 * @param arr A pointer to the array.
 * @param i1 The row index (zero-based).
 * @param i2 The column index (zero-based).
 * @return The value at the specified position.
 */
int array_get(const Array *arr, int i1, int i2);

/**
 * @brief Sets the value at a specified position in the array.
 * 
 * If the specified indices are out of bounds, the behavior is undefined.
 * Users must ensure that indices are within the range of the array dimensions.
 * This function initializes the value at the specified position.
 *
 * @param arr A pointer to the array.
 * @param i1 The row index (zero-based).
 * @param i2 The column index (zero-based).
 * @param value The value to set.
 * @return -
 */
void array_set(Array *arr, int i1, int i2, int value);

#endif /* ARRAY_H */
/**
 * @}
 */
