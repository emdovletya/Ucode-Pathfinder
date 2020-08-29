#include "pathfinder.h"

void mx_push_back_link(t_link **links, t_link *l) {
    t_link *iter = *links;

    if (!*links) {
        *links = l;
        return;
    }
    while (iter->next)
        iter = iter->next;
    iter->next = l;
}
