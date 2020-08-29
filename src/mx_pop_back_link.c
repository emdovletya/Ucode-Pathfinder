#include "pathfinder.h"

void mx_pop_back_link(t_link **links) {
    t_link *l = *links;

    if (*links != NULL) {
        if (l->next == NULL) {
            l->linked_island = NULL;
            free(l);
        } else {
            while (l->next->next)
                l = l->next;
            l->next->linked_island = NULL;
            free(l->next);
            l->next = NULL;
        }
    }
}
