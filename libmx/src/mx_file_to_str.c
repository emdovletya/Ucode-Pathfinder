#include "libmx.h"

char *mx_file_to_str(const char *file) {
    int fd = open(file, O_RDONLY);
    char buf;
    char *str;
    int len_str = 0;

    if (fd > 0) {
        while (read(fd, &buf, 1))
            len_str++;
        close(fd);
        if (len_str > 0) {
            fd = open(file, O_RDONLY);
            str = mx_strnew(len_str);
            for (int i = 0; read(fd, &buf, 1); i++)
                str[i] = buf;
            close(fd);
            return str;
        }
    }
    return NULL;
}
