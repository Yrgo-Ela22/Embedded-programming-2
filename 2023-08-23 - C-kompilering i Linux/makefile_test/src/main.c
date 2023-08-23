/********************************************************************************
 * @brief Testing compilation with GCC and CMake.
 ********************************************************************************/
#include <stdio.h>
#include <utils.h>
#include <gpiod.h> /* Included for testing linking of external library gpiod. */

/********************************************************************************
 * @brief Calculates the sum and average of integers {1, 3, 5, 7, 9} and prints
 *        in the terminal. 
 ********************************************************************************/

int main(void) {
    const int data[] = {1, 3, 5, 7, 9};
    printf("Sum:\t\t%d\n", utils_int_array_sum(data, 5));
    printf("Average:\t%lg\n", utils_int_array_average(data, 5));
    return 0;
}
