#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int len;
    char *finder;
    int index;

    if (str == 0 || sub == 0)
        return -2;
    len = mx_strlen(str);
    finder = mx_strstr(str, sub);
    if (finder == NULL)
        return -1;
    index = len - mx_strlen(finder);
    return index;
}
