#include "points.h"
#include "get_map_data.h"
#include "draw.h"
#include "fdf.h" 
#include <mlx.h>
#include <stdio.h>

int	key_hook(int keycode, t_fdf *data)
{
    printf("%d\n", keycode);
	printf("Hello from key_hook!\n");
	return (0);
}

int main(int argc, char **argv)
{
    t_fdf *data;
    t_data img;
    t_point **matrix;
    char    *path;
    int x;
    int y;
    int k;

    // path = "test_maps/pyramide.fdf";
    if (argv[1])
    {
         data = (t_fdf *)malloc(sizeof(t_fdf));
        if (!data)
            return (0);
        data->mlx = mlx_init();
        ft_get_dimensions(argv[1], data);
        data->zoom = 3;
        data->shift = 30;
        data->mlx_win = mlx_new_window(data->mlx, 960, 780 , "FDF");
        img.img = mlx_new_image(data->mlx,960, 780);
        img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
        ft_read_data(argv[1], data);
        y = 0;
        while (y < data->height)
        {
            x = 0;
            while (x < data->width)
            {
                if (x < data->width - 1){
                    ft_draw_line(&img, data, x, y, x+1, y); 
                }
                if (y <  data->height - 1)
                    ft_draw_line(&img, data, x, y, x, y+ 1);
            x++;
            }
            y++;
        }
        mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);
        mlx_key_hook(data->mlx_win, key_hook, data);
        mlx_loop(data->mlx);
    }
    else
        printf("Please provide a valid path\n");
    return (0);
}