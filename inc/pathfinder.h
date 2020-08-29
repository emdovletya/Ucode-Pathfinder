#ifndef PATHFINDER_H
#define PATHFINDER_H

#define BUF_SIZE 128
#define DELIM '\n'

#include "libmx.h"

typedef enum e_error
{
    FILE_DEXIST,
    FILE_EMPTY,
    INVLD_LINE,
} t_error;

typedef struct s_island t_island;
typedef struct s_link t_link;
typedef struct s_main t_main;
typedef struct s_path t_path;

struct s_island
{
    int index;
    char *name;
    t_link *links;  
    t_path **paths;
    t_island *next;
};

struct s_link
{
    int weight;
    t_island *linked_island;
    t_link *next;
};

struct s_main
{
    int fd;                  
    char *filename;
    int weight;
    char *lineptr;             
    int V;                     
    t_island *islands;         
    t_island *start;           
    t_island *end;                            
    t_island *start_remainder; 
};

struct s_path
{
    t_link *route;
    int dist;
    bool is_shortest;
    t_path *next;
};

void mx_find_path(t_main *m, t_link *visited, int weight, t_path **paths);
void mx_set_link(t_link **links, t_island *linked_island, int weight);
t_island *mx_get_island(t_island **islands, char *name);
void mx_add_island(t_island **islands, t_island *i);
void mx_push_back_link(t_link **links, t_link *l);
t_link *mx_create_link(t_island *linked_island);
void mx_printerr_pf(t_error err, const char *s);
bool mx_isvisited(t_link *visited, t_island *i);
void mx_add_link(t_link **links, t_link *l);
void mx_add_path(t_path **paths, t_path *p);
void mx_prepare_for_algorithm(t_main *m);
void mx_check_is_shortest(t_path *path);
t_island *mx_create_island(char *name);
t_path *mx_create_path(t_link *routes);
void mx_pop_back_link(t_link **links);
void mx_check_first_line(t_main *m);
void mx_print_all_paths(t_main *m);
void mx_check_isl_count(t_main *m);
int mx_atoi(const char *str);
t_main *mx_create_main();
void mx_parse_file(t_main *m);
void mx_find_all_paths(t_main *m);
bool mx_check_line(char *line);
t_main *mx_create_main();
void mx_find_all_paths(t_main *m);
void mx_parse_file(t_main *m);
void mx_parse_line(t_main *m);
void mx_pop_back_link(t_link **links);
void mx_prepare_for_algorithm(t_main *m);
void mx_setdistances(t_path *path);

#endif
