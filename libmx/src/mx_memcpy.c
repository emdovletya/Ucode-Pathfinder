#include "libmx.h"

void *mx_memcpy(void *restrict dst,
                const void *restrict src, size_t n) {
    unsigned char *wdst = (unsigned char *)dst;
    unsigned char *wsrc = (unsigned char *)src;

    while (n--)
        *(wdst++) = *(wsrc++);
    return dst;
}
