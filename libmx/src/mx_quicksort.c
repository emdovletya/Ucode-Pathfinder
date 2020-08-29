#include "libmx.h"

static void qswap(char **s1, char **s2) {
    char *temp = *s1;

    *s1 = *s2;
    *s2 = temp;
}

static void qcomp(char **arr, char *pivot, int *l, int *r) {
    while (mx_strlen(arr[*l]) < mx_strlen(pivot))
        (*l)++;
    while (mx_strlen(arr[*r]) > mx_strlen(pivot))
        (*r)--;
}

static void qcksort(char **arr, int *l, int *r, int *count) {
    if (*l <= *r) {
        if ((*l != *r) &&
            (mx_strlen(arr[*l]) != mx_strlen(arr[*r]))) {
            qswap(&arr[*l], &arr[*r]);
            (*count)++;
        }
        (*l)++;
        (*r)--;
    }
}

int mx_quicksort(char **arr, int left, int right) {
    int l = left;
    int r = right;
    char *pivot;
    int count = 0;

    if (!arr)
        return -1;
    pivot = arr[(left + (right - left) / 2)];
    while (l <= r) {
        qcomp(arr, pivot, &l, &r);
        qcksort(arr, &l, &r, &count);
        }
    if (left < r)
        count += mx_quicksort(arr, left, r);
    if (l < right)
        count += mx_quicksort(arr, l, right);
    return count;
}
