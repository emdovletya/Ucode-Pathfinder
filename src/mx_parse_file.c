#include "pathfinder.h"

void mx_parse_file(t_main *m) {
    int line = 2;

    mx_read_line(&m->lineptr, BUF_SIZE, DELIM, m->fd);
    mx_check_first_line(m);
    while (mx_read_line(&m->lineptr, BUF_SIZE, DELIM, m->fd) >= 0) {
        if (mx_check_line(m->lineptr))
            mx_parse_line(m);
        else
            mx_printerr_pf(INVLD_LINE, mx_itoa(line));
        mx_strdel(&m->lineptr);
        line++;
    }
    mx_check_isl_count(m);
}
