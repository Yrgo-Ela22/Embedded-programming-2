/********************************************************************************
 * @brief Contains miscellaneous utility functions for arrays.
 ********************************************************************************/
#pragma once

#include <stdio.h>

/********************************************************************************
 * @brief Calculates the sum of content in an array of integers.
 * 
 * @param data
 *        Reference to the array.
 * @param size
 *        The size of the array (the number of integers).
 * @return
 *        The sum the numbers stored in the array.
 ********************************************************************************/
static int utils_int_array_sum(const int* data, const size_t size) {
    int sum = 0;
    for (size_t i = 0; i < size; ++i) {
        sum += data[i];
    }
    return sum;
}

/********************************************************************************
 * @brief Calculates the average of the numbers stored in an array of integers.
 * 
 * @param data
 *        Reference to the array.
 * @param size
 *        The size of the array (the number of integers).
 * @return
 *        Average of the stored numbers or 0 is the array is empty.
 ********************************************************************************/
static double utils_int_array_average(const int* data, const size_t size) {
    if (size > 0) {
        return utils_int_array_sum(data, size) / (double)size;
    } else {
        return 0;
    }

}