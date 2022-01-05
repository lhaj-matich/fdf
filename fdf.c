#include "points.h"
#include "get_map_data.h"
#include "draw.h"
#include "fdf.h" 
#include <mlx.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    t_fdf *data;
    t_data img;
    t_point **matrix;
    char    *path;
    int x;
    int y;

    y = 0;
    path = "test_maps/42.fdf";
    data = (t_fdf *)malloc(sizeof(t_fdf));
    if (!data)
        return (0);
    //  data->mlx = mlx_init();
    data->zoom = 20;
    data->shift = 50;
    // data->mlx_win = mlx_new_window(data->mlx, data->width * 65, data->height * 50, "FDF");
    // img.img = mlx_new_image(data->mlx, data->width * 65, data->height * 50);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_get_dimensions(path, data);
    matrix = ft_read_data(path, data);
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            // printf("%d ", matrix[x + y]->z);
           x++;
        }
        y++;
    }
    // printf("\n");
    // printf("%d\n", i);
    // mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);
	// mlx_loop(data->mlx);
    return (0);
}