#include "libmx.h"

void mx_printerr(const char *e) {
    write(2, e, mx_strlen(e));
}
