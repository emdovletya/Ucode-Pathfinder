#include "pathfinder.h"

void mx_check_is_shortest(t_path *path) {
    t_path *iter = path;
    int min_dist = path->dist;

    while (iter) {
        if (iter->dist < min_dist)
            min_dist = iter->dist;
        iter->is_shortest = false;
        iter = iter->next;
    }
    iter = path;
    while (iter) {
        if (iter->dist == min_dist)
            iter->is_shortest = true;
        iter = iter->next;
    }
}
