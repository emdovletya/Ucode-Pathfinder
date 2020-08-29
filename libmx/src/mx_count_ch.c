#include "libmx.h"

int mx_count_ch(const char *str, char delim) {
    int count = 0;

    while (*str && *str != delim) {
        count++;
        str++;
    }
    return count;
}
