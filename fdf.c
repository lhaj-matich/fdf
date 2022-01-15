#include "get_map_data.h"
#include "fdf.h" 
#include "draw.h"
#include "points.h"
#include <mlx.h>
#include <stdio.h>

int	key_hook(int keycode, t_fdf *data)
{
    printf("%d\n", keycode);
	printf("Hello from key_hook!\n");
	return (0);
}

// This function will be responsible for closing the windows
int close_window(t_fdf *data)
{
    (void) key_hook;
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit(0);
    return (0);
}

void    ft_draw_map(t_fdf *data)
{
    int x;
    int y;

    data->img.img = mlx_new_image(data->mlx,960, 780);
    data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);

    y = 0;
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
    mlx_key_hook(data->mlx_win, key_hook, data);
    mlx_loop(data->mlx);
}

int main(int argc, char **argv)
{
    t_fdf *data;
    t_data img;
    if (argv[1])
    {
        data = (t_fdf *)malloc(sizeof(t_fdf));
        if (!data)
            return (0);
        data->zoom = 3;
        data->img = img;
        data->shift = 30;
        data->mlx = mlx_init();
        data->mlx_win = mlx_new_window(data->mlx, 960, 780 , "FDF");
        ft_get_dimensions(argv[1], data);
        ft_read_data(argv[1], data);
        ft_draw_map(data);
    }
    else
        printf("Please provide a valid path\n");
    return (0);
}