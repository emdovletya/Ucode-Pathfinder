#include "pathfinder.h"

void mx_add_link(t_link **links, t_link *l) {
    if (!*links) {
        *links = l;
        return;
    }
    l->next = *links;
    *links = l;
}
