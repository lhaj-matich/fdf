#include "fdf.h"
#include "draw.h"
#include "settings.h"
#include <mlx.h>
#include <stdlib.h>

void    ft_translate(int key, t_fdf *param)
{
    if (key == KEYDOWN)
        param->shift_y += 20;
    else if (key == KEYUP)
        param->shift_y -= 20;
    else if (key == KEYLEFT)
        param->shift_x -= 20;
    else if (key == KEYRIGHT)
        param->shift_x += 20;
}

void    ft_zoom(int key, t_fdf *param)
{
    if (key == KEYQ)
    {
        param->zoom += 1;
        param->shift_x -= param->zoom;
        param->shift_y -= param->zoom;
    }
    else if (key == KEYE)
    {
        param->zoom -= 1;
        param->shift_x += param->zoom;
        param->shift_y += param->zoom;
    }
}

void    ft_increase_alltitude(int key, t_fdf *param)
{
    if (key == KEYW)
        param->z += 2;
    else if (key == KEYS)
        param->z -= 2;
}

void    ft_rotate(int key, t_fdf *param)
{
    if (key == KEYX)
        param->x_angle += 0.2;
    else if (key == KEYY)
        param->y_angle += 0.2;
    else if (key == KEYZ)
        param->z_angle += 0.2;
}

int	handle_keys(int key, t_fdf *param)
{
    printf("%d\n", key);
    ft_translate(key, param);
    ft_zoom(key, param);
    ft_rotate(key, param);
    ft_increase_alltitude(key, param);
	mlx_clear_window(param->mlx, param->mlx_win);
	mlx_destroy_image(param->mlx, param->img.img);
	ft_draw_map(param);
	return (0);
}

int close_window(t_fdf *data)
{
    mlx_destroy_image(data->mlx, data->img.img);
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(0);
    return (0);
}
