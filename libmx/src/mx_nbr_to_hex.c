#include "libmx.h"

static char convert_to_hex (int n) {
    if ((n > 9) && (n <= 16))
        return n += 87;
    else if ((n < 10) && (n >= 0))
        return n += 48;
    return -1;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    char *str = 0;
    char len = 0;
    int i = 0;
    unsigned long num = nbr;

    for (; num > 0; num /= 16, len++);
    str = (char *)malloc(len + 1);
    for (i = 0; i < len; i++) {
        str[len - i -1] = convert_to_hex(nbr % 16);
        nbr /= 16;
    }
    str[(int)len] = 0;
    return str;
}
