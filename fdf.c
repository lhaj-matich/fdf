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
    char    *path;
    int x;
    int y;

    y = 0;
    path = "test_maps/42.fdf";
    data = (t_fdf *)malloc(sizeof(t_fdf));
    if (!data)
        return (0);
    //  data->mlx = mlx_init();
    data->height = ft_get_lines(path);
    data->zoom = 20;
    data->shift = 50;
	ft_read_data(path, data);
    // data->mlx_win = mlx_new_window(data->mlx, data->width * 65, data->height * 50, "FDF");
    // img.img = mlx_new_image(data->mlx, data->width * 65, data->height * 50);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    while (y < data->height)
    {
        x = 0;
        while (x < data->width)
        {
            printf("%d ", data->matrix[x + y]->z);
            x++;
        }
        y++;
        printf("\n");
    }
    // mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);
	// mlx_loop(data->mlx);
    return (0);
}