#include "libmx.h"

bool mx_isdigit(int n) {
    if (n >= 48 && n <= 57)
        return true;
    else
        return false;
}
