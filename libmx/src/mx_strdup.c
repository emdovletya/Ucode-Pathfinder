#include "libmx.h"

char *mx_strdup(const char *s1) {
    char *new_str = mx_strnew(mx_strlen(s1));
 
    if (new_str == NULL)
    	return NULL;
    mx_strcpy(new_str, s1);
    return new_str;
}
