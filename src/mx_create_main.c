#include "pathfinder.h"

t_main *mx_create_main() {
    t_main *m = malloc(sizeof(t_main));

    m->filename = NULL;
    m->islands = NULL;
    m->lineptr = NULL;
    m->start = NULL;
    m->end = NULL;
    m->start_remainder = NULL;
    return m;
}
