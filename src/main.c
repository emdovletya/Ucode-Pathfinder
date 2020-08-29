#include "pathfinder.h"

static void reverse(t_path **head_ref) {
    t_path *prev = NULL;
    t_path *current = *head_ref;
    t_path *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

static void reverse_paths(t_main *m) {
    t_island *isl = m->islands;

    while (isl) {
        for (int i = 0; i < m->V; i++)
            reverse(&(isl->paths[i]));
        isl = isl->next;
    }
}

int main(int argc, char *argv[]) {
    int fd;
    t_main *m;

    if (argc != 2)
        mx_printerror("usage: ./pathfinder [filename]");
    fd = open(argv[1], O_RDONLY);
    if (read(fd, 0, 0) < 0)
        mx_printerr_pf(FILE_DEXIST, argv[1]);
    m = mx_create_main();
    m->filename = argv[1];
    m->fd = fd;
    mx_parse_file(m);
    mx_prepare_for_algorithm(m);
    mx_find_all_paths(m);
    reverse_paths(m);
    mx_print_all_paths(m);

    return 0;
}
