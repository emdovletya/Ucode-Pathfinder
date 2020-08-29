#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int haystack_len = mx_strlen(haystack);
    int needle_len;

    if (needle == NULL)
        return (char*)haystack;
    needle_len = mx_strlen(needle);   
    for (int i = 0; i < haystack_len; i++) {
        if ((*haystack == *needle) 
            && mx_strncmp(haystack, needle, needle_len) == 0) {
            return (char*)haystack;
        }
        ++haystack;
    }
    return NULL;
}
