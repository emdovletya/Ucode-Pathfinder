#include "pathfinder.h"

bool mx_isvisited(t_link *visited, t_island *i) {
    t_link *iter = visited;

    if (!iter)
        return false;
    while (iter) {
        if (iter->linked_island->name == i->name)
            return true;
        iter = iter->next;
    }
    return false;
}
