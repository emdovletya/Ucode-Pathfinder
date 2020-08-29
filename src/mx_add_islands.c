#include "pathfinder.h"

void mx_add_island(t_island **islands, t_island *i) {
    if (!*islands) {
        *islands = i;
        return;
    }
    i->next = *islands;
    *islands = i;
}
