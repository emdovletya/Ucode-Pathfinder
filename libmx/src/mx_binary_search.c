#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    unsigned first = *count = 0;
    unsigned last = size - 1;
    unsigned middle;

    while (first <= last) {
        middle = (last + first) / 2;
        ++*count;
        if (mx_strcmp(arr[middle], s) == 0)
            return middle;
        else if (mx_strcmp(arr[middle], s) > 0) {
            last = middle - 1;
        }
        else 
            first = middle + 1;
    }
    *count = 0;
    return -1;
}
