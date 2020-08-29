#include "pathfinder.h"

void mx_check_first_line(t_main *m) {
    if (m->lineptr == NULL)
        mx_printerr_pf(FILE_EMPTY, m->filename);
    else if (mx_isnumber(m->lineptr)) {
        m->V = mx_atoi(m->lineptr);
        mx_strdel(&m->lineptr);
    } else
        mx_printerror("error: line 1 is not valid");
}
