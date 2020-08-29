#include "libmx.h"

char *mx_strtrim(const char *str) {
    char *end;
    int r_spc = 0;
    char *out;

    if (!str)
        return NULL;
    while (*str && mx_isspace(*str)) {
        str++;
    }
    if (*str == 0)
        return mx_strnew(0);
    end = (char *)str + mx_strlen(str) - 1;
    while ((end > str) && mx_isspace(*end)) {
        end--;
        r_spc++;
    }
    out = mx_strnew(mx_strlen(str) - r_spc);
    if (!(out = mx_strncpy(out, str, mx_strlen(str) - r_spc)))
        return NULL;  
    return out;
}
