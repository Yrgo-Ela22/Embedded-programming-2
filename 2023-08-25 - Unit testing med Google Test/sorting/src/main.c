/********************************************************************************
 * @brief Example of sorting and printing numbers stored in arrays.
 ********************************************************************************/
#include <utils.h>

/********************************************************************************
 * @brief Sorts arrays containing numbers in ascending and descending order.
 *        The array content are printed after each sort.
 ********************************************************************************/
int main(void) {
    int integers[] = {-1, 5, -2, 4, 100, 55, 20, 20, -100, 2};
    double floats[] = {2.2, -2.2, 5.78, 5, 10, 8.2, 8.1, 4.9, 100.1, -100.09};
    const size_t num_integers = UTILS_ARRAY_SIZE(integers, int);
    const size_t num_floats = UTILS_ARRAY_SIZE(floats, double);

    utils_sort_int(integers, num_integers);
    utils_print_int(integers, num_integers, 0);
    utils_sort_int_reverse(integers, num_integers);
    utils_print_int(integers, num_integers, 0);

    utils_sort_double(floats, num_floats);
    utils_print_double(floats, num_floats, 0);
    utils_sort_double_reverse(floats, num_floats);
    utils_print_double(floats, num_floats, 0);
    return 0;
}