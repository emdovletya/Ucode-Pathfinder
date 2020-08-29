#include "pathfinder.h"

void mx_parse_line(t_main *m) {
    char **ptr;
    char *ptr1;
    t_island *island1;
    t_island *island2;
    int weight;

    ptr = mx_strsplit(m->lineptr, '-');
    island1 = mx_get_island(&m->islands, mx_strdup(ptr[0]));
    ptr1 = mx_strdup(ptr[1]);
    mx_del_strarr(&ptr);
    ptr = mx_strsplit(ptr1, ',');
    mx_strdel(&ptr1);
    island2 = mx_get_island(&m->islands, mx_strdup(ptr[0]));
    weight = mx_atoi(ptr[1]);
    mx_del_strarr(&ptr);
    mx_set_link(&island1->links, island2, weight);
    mx_set_link(&island2->links, island1, weight);
}
