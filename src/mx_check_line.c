#include "pathfinder.h"

bool mx_check_line(char *line) {
    int i = -1;
    int island1 = 0;
    int island2 = 0;

    if (mx_strcmp(line, "") == 0)
        return false;
    while (mx_isalpha(line[++i]))
        island1++;
    if (line[i] != '-')
        return false;
    while (mx_isalpha(line[++i]))
        island2++;
    if (!island1 || !island2)
        return false;
    if (line[i++] != ',')
        return false;
    if (!(line[i]) || !mx_isnumber(line + i))
        return false;
    return true;
}
