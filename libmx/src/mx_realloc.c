#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    void *new_ptr = NULL;
    size_t ptr_len;

    if (size <= 0 && ptr) {
        free(ptr);
        return NULL;
    }
    else if (!ptr && size)
        return malloc(size);
    else {
        ptr_len = malloc_size(ptr);
        if (ptr_len > size)
            new_ptr = (void *)malloc(ptr_len);
        else
            new_ptr = (void *)malloc(size);
        new_ptr = mx_memmove(new_ptr, ptr, size);
        free(ptr);
        return new_ptr ? new_ptr : NULL;
    }
}
