#include "libmx.h"

int mx_list_size(t_list *list) {
    t_list *current = list;
    int ret = 0;

    while (current) {
        current = current->next;
        ret++;
    }
    return ret;
}
