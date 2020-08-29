#include "pathfinder.h"

void mx_setdistances(t_path *path) {
    t_path *iter = path;
    t_link *rt;
    int distance;

    while (iter) {
        if (!iter->dist) {
            rt = iter->route;
            distance = 0;
            while (rt) {
                distance += rt->weight;
                rt = rt->next;
            }
            iter->dist = distance;
            distance = 0;
        }
        iter = iter->next;
    }
}
