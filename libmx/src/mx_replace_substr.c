#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, 
                        const char *replace) {
    char *out;
    int i = 0;
    int c_sb;

    if (!str || !sub || !replace)
        return NULL;
    c_sb = mx_count_substr(str, sub);
    out = mx_strnew(mx_strlen(str) + 
                    c_sb * (mx_strlen(replace) - mx_strlen(sub)));
    while (*str) {
        if (mx_strstr(str, sub) == str) {
            mx_strcpy(&out[i], replace);
            i += mx_strlen(replace);
            str += mx_strlen(sub);
        }
        else
            out[i++] = *str++;
    }
    out[i] = '\0';
    return out;
}
