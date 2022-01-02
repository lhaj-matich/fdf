#ifndef POINTS_H
#define POINTS_H

#include <stdlib.h>

typedef struct point {
    int color;
    int z;
    struct point *next;
} s_point;

s_point *create_point(int color, int alltitude);
s_point *last_point(s_point *lst);
s_point *append_point(s_point *head, s_point *point);

#endif