#include "pathfinder.h"

void mx_add_path(t_path **paths, t_path *p) {
    if (!*paths) {
        *paths = p;
        return;
    }
    p->next = *paths;
    *paths = p;
}
