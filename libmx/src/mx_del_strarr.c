#include "libmx.h"

void mx_del_strarr(char ***arr) {
    int i = 0;
    char **temp;
    temp = *arr;
    
    if (!arr || !*arr)
        return; 
    while (temp[i]) {
        free((char *)temp[i]);
        i++;
    }
    free((char **)temp);
    *arr = NULL;
}
