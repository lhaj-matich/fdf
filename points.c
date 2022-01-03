#include "points.h"

t_point *create_point(int alltitude , int color) 
{
    t_point *point;

    point = malloc(sizeof(t_point));
    if (!point)
        return (NULL);
    point->color = color;
    point->z = alltitude;
    point->next = NULL;
    return (point);
}

t_point *append_point(t_point *head, t_point *point)
{
    t_point *lst_point;

    if (head == NULL)
        return (point);
    lst_point = last_point(head);
    lst_point->next = point;
    return (head);
}

t_point *last_point(t_point *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}