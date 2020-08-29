#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    char *new_str;
    size_t s_len = (size_t)mx_strlen(s1);

    if (s_len < n) {
    	if (!(new_str = mx_strnew(s_len)))
    		return NULL;
    	mx_strcpy(new_str, s1);
    }
    else {
    	if (!(new_str = mx_strnew(n)))
    		return NULL;
    	mx_strncpy(new_str, s1, n);
    }
    return new_str;
}
