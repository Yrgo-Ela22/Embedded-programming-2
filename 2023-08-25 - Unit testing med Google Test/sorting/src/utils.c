#include <utils.h>

bool utils_sort_int(int* data, const size_t size) {
    if (!data || size == 0) return false;
    for (int* i = data; i < data + size - 1; ++i) {
        for (int* j = i + 1; j < data + size; ++j) {
            if (*i > *j) {
                const int temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
    return true;
}

bool utils_sort_int_reverse(int* data, const size_t size) {
    if (!data || size == 0) return false;
    for (int* i = data; i < data + size - 1; ++i) {
        for (int* j = i + 1; j < data + size; ++j) {
            if (*j > *i) {
                const int temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
    return true;
}

bool utils_sort_double(double* data, const size_t size) {
    if (!data || size == 0) return false;
    for (double* i = data; i < data + size - 1; ++i) {
        for (double* j = i + 1; j < data + size; ++j) {
            if (*i > *j) {
                const double temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
    return true;
}

bool utils_sort_double_reverse(double* data, const size_t size) {
    if (!data || size == 0) return false;
    for (double* i = data; i < data + size - 1; ++i) {
        for (double* j = i + 1; j < data + size; ++j) {
            if (*j > *i) {
                const double temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
    return true;
}

void utils_print_int(const int* data, const size_t size, FILE* ostream) {
    if (!data) return;
    if (!ostream) ostream = stdout;
    fprintf(ostream, "--------------------------------------------------------------------------------\n");
    for (const int* i = data; i < data + size; ++i) {
        fprintf(ostream, "%d\n", *i);
    }
    fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
}

void utils_print_double(const double* data, const size_t size, FILE* ostream) {
    if (!data) return;
    if (!ostream) ostream = stdout;
    fprintf(ostream, "--------------------------------------------------------------------------------\n");
    for (const double* i = data; i < data + size; ++i) {
        fprintf(ostream, "%lg\n", *i);
    }
    fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
}
