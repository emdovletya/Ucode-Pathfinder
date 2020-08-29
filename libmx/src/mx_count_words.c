#include "libmx.h"

int mx_count_words(const char *str, char c) {
    int count_words = 0;
    int trap = 0;

    if (str == NULL)
        return -1;   
    while (*str) {
        if (*str != c && mx_isspace(*str) == 0 && trap == 0) {
            count_words++;
            trap = 1;
        }
        else if (*str == c)
            trap = 0;
        str++;
    }
    return count_words;
}
