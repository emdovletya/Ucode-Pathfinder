#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count = 0;
    char *tmp;
    int sub_len;

    if (str == NULL || sub == NULL)
        return -1;
    sub_len = mx_strlen(sub);
    tmp = (char *)str;
    while (*tmp && (tmp = mx_strstr(tmp, sub))) {
        tmp += sub_len;
        count++;
    }
    return count;
}
