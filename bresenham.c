#include <math.h>
#include <mlx.h>
#include "fdf.h"
#include "draw.h"
#include "points.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
    if ((x >=0 && x < 960) && ( y >= 0  && y < 780))
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

int ft_compare(int a, int b)
{
    if (a < b)
        return (1);
    else
        return (-1);
}

t_bresenham *ft_init_bresenham(t_dot *a, t_dot *b)
{
    t_bresenham *params;

    params = malloc(sizeof(t_bresenham));
    if (!params)
        return (NULL);
    params->dx = abs(b->x - a->x);
    params->sx = ft_compare(a->x, b->x);
    params->dy = -abs(b->y - a->y);
    params->sy = ft_compare(a->y, b->y);
    params->err = params->dx + params->dy;
    return (params);
}

void ft_draw_line(t_fdf *data, t_dot *a, t_dot *b)
{
    t_bresenham *params;
    int e2;

    params = ft_init_bresenham(a, b);
    while (1)
    {
        my_mlx_pixel_put(&data->img, a->x, a->y, a->color);
        if (a->x == b->x && a->y == b->y)
			break ;
        params->e2 = 2 * params->err;
        if (params->e2 >= params->dy)
        {
            params->err += params->dy;
            a->x += params->sx;
        }
        if (params->e2 <= params->dx)
        {
            params->err += params->dx;
            a->y += params->sy;
        }    
    }
}