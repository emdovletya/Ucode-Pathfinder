#include "pathfinder.h"

void mx_find_path(t_main *m, t_link *visited, int weight, t_path **paths) {
    t_link *iter = m->start->links;
    t_link *visited_island = NULL;

    if (mx_isvisited(visited, m->start))
        return;
    visited_island = mx_create_link(m->start);
    visited_island->weight = weight;
    mx_push_back_link(&visited, visited_island);
    if (m->start == m->end)
        mx_add_path(&paths[m->end->index], mx_create_path(visited));
    else
        while (iter) {
            m->start = iter->linked_island;
            mx_find_path(m, visited, iter->weight, paths);
            iter = iter->next;
        }
    mx_pop_back_link(&visited);
}
