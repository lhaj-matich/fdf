#include "get_map_data.h"
#include "fdf.h" 
#include "draw.h"
#include "points.h"
#include "settings.h"
#include <mlx.h>
#include <stdio.h>

int	handle_keys(int key, t_fdf *param)
{
    printf("%d\n", param->zoom);
    if (key == KEYDOWN)
        param->shift_y -= 20;
    else if (key == KEYUP)
        param->shift_y += 20;
    else if (key == KEYLEFT)
        param->shift_x-= 20;
    else if (key == KEYRIGHT)
        param->shift_x += 20;
    else if (key == KEYQ)
    {
        param->zoom += 10;
        param->shift_x -= param->zoom;
        param->shift_y -= param->zoom;
    }
    else if (key == KEYE)
    {
        param->zoom -= 10;
        param->shift_x += param->zoom;
        param->shift_y += param->zoom;
    }
    printf("%d\n", key);
	mlx_clear_window(param->mlx, param->mlx_win);
	mlx_destroy_image(param->mlx, param->img.img);
	ft_draw_map(param);
	return (0);
}

// This function will be responsible for closing the windows
int close_window(t_fdf *data)
{
    mlx_destroy_image(data->mlx, data->img.img);
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(0);
    return (0);
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
                ft_draw_line(&data->img, data, x, y, x+1, y); 
            if (y <  data->height - 1)
                ft_draw_line(&data->img, data, x, y, x, y+ 1);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
    mlx_hook(data->mlx_win, 17, 0, close_window, data);
    mlx_key_hook(data->mlx_win, handle_keys, data);
    mlx_loop(data->mlx);
}

int ft_init_fdf(t_fdf *params)
{
    t_data img;

    params->img = img;
    params->zoom = 10;
    params->z = 0;
    params->shift_x = 960 / 2;
    params->shift_y = 780 / 2;
    params->mlx = mlx_init();
    params->mlx_win = mlx_new_window(params->mlx, 960, 780 , "FDF By Sh4d0w4lk3r");
}

int main(int argc, char **argv)
{
    t_fdf *data;
    
    if (argv[1])
    {
        data = (t_fdf *)malloc(sizeof(t_fdf));
        if (!data)
            return (0);
        ft_init_fdf(data);
        ft_get_dimensions(argv[1], data);
        ft_read_data(argv[1], data);
        ft_draw_map(data);
    }
    else
        printf("Please provide a valid path (490)\n");
    return (0);
}