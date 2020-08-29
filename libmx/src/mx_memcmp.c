#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
    unsigned char *ws1 = (unsigned char *)s1;
    unsigned char *ws2 = (unsigned char *)s2;

    while (n--) {
        if (*ws1 != *ws2)
            return *ws1 - *ws2;
        ws1++;
        ws2++;
    }
    return 0;
}
