/********************************************************************************
 * @brief Contains miscellaneous utility functions for arrays.
 ********************************************************************************/
#pragma once

#include <stdio.h>
#include <stdbool.h>

/********************************************************************************
 * @brief Provides the size of specified array in number of elements it can hold.
 * 
 * @param array
 *        The array in question (note: don't pass a reference).
 * @return 
 *        The size of the array.
 ********************************************************************************/
#define UTILS_ARRAY_SIZE(array) sizeof(array) > 0 ? sizeof(array) / sizeof(array[0]) : (size_t)(0)

/********************************************************************************
 * @brief Sorts content of referenced int array in ascending order.
 * 
 * @param data
 *        Reference to array containing integers.
 * @param size
 *        The size of the array, i.e. the number of elements to sort.
 * @return 
 *        True if the array content was sorted, false if the array was empty
 *        of a nullptr was passed.
 ********************************************************************************/
bool utils_sort_int(int* data, const size_t size);

/********************************************************************************
 * @brief Sorts content of referenced int array in descending order.
 * 
 * @param data
 *        Reference to array containing integers.
 * @param size
 *        The size of the array, i.e. the number of elements to sort.
 * @return 
 *        True if the array content was sorted, false if the array was empty
 *        of a nullptr was passed.
 ********************************************************************************/
bool utils_sort_int_reverse(int* data, const size_t size);

/********************************************************************************
 * @brief Sorts content of referenced double array in ascending order.
 * 
 * @param data
 *        Reference to array containing floating-point numbers.
 * @param size
 *        The size of the array, i.e. the number of elements to sort.
 * @return 
 *        True if the array content was sorted, false if the array was empty
 *        of a nullptr was passed.
 ********************************************************************************/
bool utils_sort_double(double* data, const size_t size);

/********************************************************************************
 * @brief Sorts content of referenced double array in descending order.
 * 
 * @param data
 *        Reference to array containing floating-point numbers.
 * @param size
 *        The size of the array, i.e. the number of elements to sort.
 * @return 
 *        True if the array content was sorted, false if the array was empty
 *        of a nullptr was passed.
 ********************************************************************************/
bool utils_sort_double_reverse(double* data, const size_t size);

/********************************************************************************
 * @brief Prints numbers stored in referenced int array to an arbitrary output 
 *        stream. As default (if the output stream is passed as a nullptr), 
 *        the terminal is used to print the array content.
 * 
 * @param data
 *        Reference to array containing the integers to print.
 * @param ostream
 *        Reference to selected output stream (default = stdout).
 ********************************************************************************/
void utils_print_int(const int* data, const size_t size, FILE* ostream);

/********************************************************************************
 * @brief Prints numbers stored in referenced double array to selected output 
 *        stream. As default (if the output stream is passed as a nullptr), 
 *        the terminal is used to print the numbers.
 * 
 * @param data
 *        Reference to array containing the floating-point numbers to print.
 * @param ostream
 *        Reference to selected output stream (default = stdout).
 ********************************************************************************/
void utils_print_double(const double* data, const size_t size, FILE* ostream);