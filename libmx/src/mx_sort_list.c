#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    t_list *ilst;
    t_list *jlst;
    
    if (lst != NULL) {
        for (ilst = lst; ilst != NULL; ilst = ilst->next) {
            for (jlst = ilst->next; jlst != NULL; jlst = jlst->next) {
                if (cmp(ilst->data, jlst->data) == true)
                    mx_swap_data(jlst, ilst);
            }
        }
    }
    return lst;
}
