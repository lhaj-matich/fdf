#ifndef POINTS_H
#define POINTS_H

#include <stdlib.h>

typedef struct s_point {
    int color;
    int z;
} t_point;

t_point *create_point(int alltitude , int color);

#endif