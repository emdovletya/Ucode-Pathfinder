#include "pathfinder.h"

void mx_find_all_paths(t_main *m) {
    m->start = m->islands;
    t_link *visited = NULL;

    while (m->start) {
        m->end = m->start->next;
        m->start_remainder = m->start;
        while (m->end) {
            if (m->start != m->end) {
                mx_find_path(m, visited, 0, m->start->paths);
                m->start = m->start_remainder;
                mx_setdistances(m->start->paths[m->end->index]);
                mx_check_is_shortest(m->start->paths[m->end->index]);
            }
            m->end = m->end->next;
        }
        m->start = m->start->next;
    }
}
