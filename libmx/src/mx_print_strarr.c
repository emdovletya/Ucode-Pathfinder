#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    int size = 0;

    if (!arr || !delim)
        return;
    while (arr[size]) {
        mx_printstr(arr[size]);
        if (arr[size + 1] != '\0')
        	mx_printstr(delim);
        size++;
    }
    mx_printchar('\n');
}
