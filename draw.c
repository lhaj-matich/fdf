#include <math.h>
#include <stdio.h>
#include <mlx.h>
#include "fdf.h"
#include "draw.h"
#include "points.h"
#include "keys.h"


void	ft_xrotation(int *x, int *y, int *z, double angle)
{
	(void)(x);
	*y = *y * cos(angle) + *z * sin(angle);
	*z = -(*y) * sin(angle) + *z * (cos(angle));
}

void	ft_yrotation(int *x, int *y, int *z, double angle)
{
	(void)(y);
	*x = *x * cos(angle) + *z * sin(angle);
	*z = -(*x) * sin(angle) + *z * (cos(angle));
}

void	ft_zrotation(int *x, int *y, int *z, double angle)
{
	(void)(z);
	*x = *x * cos(angle) - *y * sin(angle);
	*y = (*x) * sin(angle) + *y * (cos(angle));
}

void    ft_translate_map(int *x, int *y, t_fdf *data)
{  
    *x += data->shift_x;
    *y += data->shift_y;
}

void    ft_zoom_map(int *x, int *y, t_fdf *data)
{  
    if (data->zoom < 2)
        data->zoom = 1;
    *x *= data->zoom;
    *y *= data->zoom;
}

void ft_isometric(int *x, int *y, int z)
{
    int p_x;
    int p_y;

    p_x = *x;
    p_y = *y;
    *x = (p_x - p_y) * cos(0.523599);
    *y  = (p_x + p_y) * sin(0.523599) - z;
}

int  ft_get_color(int index, t_fdf *data)
{
    int color;
    int alltitude;

    color = data->matrix[index]->color;
    alltitude = data->matrix[index]->z;
    if (color > 0) 
        return color;
    else if (alltitude > 0 && color == 0)
        return (0x00FF0000);
    else
        return (0xfffffff);
}

t_dot   *ft_setup_point(t_fdf *data, int x, int y)
{
    t_dot *point;
    int index;
    int alltitude;

    point = malloc(sizeof(t_dot));
    if (!point)
        return (NULL);
    index = y * data->width + x;
    alltitude = data->matrix[index]->z;
    if (alltitude > 0)
        alltitude += data->z;
    ft_zoom_map(&x, &y, data);
    ft_isometric(&x, &y, alltitude);
    ft_xrotation(&x, &y, &alltitude, data->x_angle);
    ft_yrotation(&x, &y, &alltitude, data->y_angle);
    ft_zrotation(&x, &y, &alltitude, data->z_angle);
    ft_translate_map(&x, &y , data);
    point->x = x;
    point->y = y;
    point->color = ft_get_color(index, data);
    return (point);
}

void    ft_draw_map(t_fdf *data)
{
    int x;
    int y;

    y = 0;
    data->img.img = mlx_new_image(data->mlx,960, 780);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            if (x < data->width - 1)
                ft_draw_line(data, ft_setup_point(data ,x, y), ft_setup_point(data ,x + 1, y));
            if (y <  data->height - 1)
                ft_draw_line(data, ft_setup_point(data, x, y), ft_setup_point(data, x, y + 1));
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
    mlx_hook(data->mlx_win, 17, 0, close_window, data);
    mlx_key_hook(data->mlx_win, handle_keys, data);
    mlx_loop(data->mlx);
}