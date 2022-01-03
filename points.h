#ifndef POINTS_H
#define POINTS_H

#include <stdlib.h>

typedef struct s_point {
    int color;
    int z;
    struct s_point *next;
} t_point;

t_point *create_point(int color, int alltitude);
t_point *last_point(t_point *lst);
t_point *append_point(t_point *head, t_point *point);

#endif