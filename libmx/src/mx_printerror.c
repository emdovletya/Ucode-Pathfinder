#include "libmx.h"

void mx_printerror(char *comment) {
    mx_printerr(comment);
    mx_printerr("\n");
    exit(1);
}
