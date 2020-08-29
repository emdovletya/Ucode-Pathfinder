#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *current = *list;

    if (*list == NULL)
        *list = mx_create_node(data);
    else {
    	while (current->next)
        	current = current->next;
    	current->next = malloc(sizeof(t_list));
    	current->next->data = data;
    	current->next->next = NULL;
    }
}
