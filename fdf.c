#include "fdf.h"
#include <stdio.h>

int main(void)
{
    s_point *head, *tmp;
    int i;

    head = NULL;
    i = 0;
    while (i < 10)
    {
        tmp = create_point(i + 1, i + 2);
        head = append_point(head, tmp);
        i++;
    }
    
    while (head != NULL)
    {
        printf("Color: %d\n", head->color);
        printf("Alltitude: %d\n", head->z);
        head = head->next;
    }
}