#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *ws = (unsigned char *)s + n;

    while (n--) {
        if (*ws != (unsigned char)c)
            ws--;
        else
            return ws;
    }
    return NULL;
}
