#include "pathfinder.h"

void mx_check_isl_count(t_main *m) {
    t_island *iter = m->islands;
    int count = 0;

    while (iter) {
        count++;
        iter = iter->next;
    }
    if (m->V != count)
        mx_printerror("error: invalid number of islands");
}
