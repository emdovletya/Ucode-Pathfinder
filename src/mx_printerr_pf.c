#include "pathfinder.h"

void mx_printerr_pf(t_error err, const char *s) {
    switch (err) {
    case FILE_DEXIST:
        mx_printerr("error: file ");
        mx_printerr(s);
        mx_printerr(" does not exist");
        break;
    case FILE_EMPTY:
        mx_printerr("error: file ");
        mx_printerr(s);
        mx_printerr(" is empty");
        break;
    case INVLD_LINE:
        mx_printerr("error: line ");
        mx_printerr(s);
        mx_printerr(" is not valid");
        break;
    }
    mx_printerr("\n");
    exit(1);
}
