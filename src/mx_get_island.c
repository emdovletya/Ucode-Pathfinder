#include "pathfinder.h"

t_island *mx_get_island(t_island **islands, char *name) {
    t_island *iter = *islands;
    t_island *last_island;

    if (!iter) {
        *islands = mx_create_island(name);
        return *islands;
    }
    while (iter) {
        if (mx_strcmp(iter->name, name) == 0) {
            mx_strdel(&name);
            return iter;
        }
        if (iter->next == NULL)
            last_island = iter;
        iter = iter->next;
    }
    last_island->next = mx_create_island(name);
    return last_island->next;
}
