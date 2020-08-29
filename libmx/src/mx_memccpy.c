#include "libmx.h"

void *mx_memccpy(void *restrict dst,
                 const void *restrict src, int c, size_t n) {
    unsigned char *wdst = (unsigned char *)dst;
    unsigned char *wsrc = (unsigned char *)src; 
    size_t i = 0;

    if (n == 0)
        return NULL;
    while (i < n) {
        wdst[i] = wsrc[i];
        if (wsrc[i] == c)
            return (void *)&(wdst[i+1]);
        i++;
    }
    return NULL;
}
