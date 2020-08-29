#include "pathfinder.h"

void mx_prepare_for_algorithm(t_main *m) {
    t_island *iter = m->islands;
    int i = 0;

    while (iter) {
        iter->index = i;
        iter->paths = malloc(sizeof(t_path *) * m->V);
        for (int i = 0; i < m->V; i++)
            iter->paths[i] = NULL;
        i++;
        iter = iter->next;
    }
}
