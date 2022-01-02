#include "fdf.h"

s_point *create_point(int color, int alltitude) 
{
    s_point *point;

    point = malloc(sizeof(s_point));
    if (!point)
        return (NULL);
    point->color = color;
    point->z = alltitude;
    point->next = NULL;
    return (point);
}

s_point *append_point(s_point *head, s_point *point)
{
    s_point *lst_point;

    if (head == NULL)
        return (point);
    lst_point = last_point(head);
    lst_point->next = point;
    return (head);
}

s_point *last_point(s_point *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next != NULL)
        lst = lst->next;
    return (lst);
}