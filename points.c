#include "points.h"

t_point *create_point(int alltitude , int color) 
{
    t_point *point;

    point = malloc(sizeof(t_point));
    if (!point)
        return (NULL);
    point->z = alltitude;
    point->color = color;
    return (point);
}