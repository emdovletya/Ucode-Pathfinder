#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len,
                const void *little, size_t little_len) {
    unsigned char *b = (unsigned char*)big;
    unsigned char *l = (unsigned char*)little;

    if (!little)
        return (void *)big;
    if (!big_len || !little_len || little_len > big_len)
        return NULL;
    if (little_len == 1)
        return mx_memchr(big, (int)*l, big_len);   
    for (size_t i = 0; i <= (big_len - little_len); i++) {
        if ((*b == *l) && mx_memcmp(b, l, little_len) == 0)
            return (void *)b;
        b++;
    }
    return NULL;
}
