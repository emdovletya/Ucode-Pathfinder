#include "libmx.h"

void mx_pop_back(t_list **head) {
	t_list *current = NULL;

	if (head && *head && (*head)->next) {
    	current = *head;
    	while (current->next->next)
    		current = current->next;
    	free(current->next);
    	current->next = NULL;
    }
    else if (head && *head) {
        free(*head);
        *head = NULL;
    }
}
