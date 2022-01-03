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

    x = 0;
    y = 0;
    path = "test_maps/42.fdf";
    data = (t_fdf *)malloc(sizeof(t_fdf));
    if (!data)
        return (0);
    data->mlx = mlx_init();
    data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "FDF");
    data->height = ft_get_lines(path);
    data->zoom = 40;
    img.img = mlx_new_image(data->mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_read_data(path, data);
    while (x <= data->width)
    {
        y = 0;
        while (y <= data->height)
        { 
            if (x < data->width)
                ft_draw_line(&img, data, x, y, x + 1, y, data->matrix[x]->z);
            if (y < data->height)
                ft_draw_line(&img, data, x, y, x, y + 1, data->matrix[x]->z);
            data->matrix[x] = data->matrix[x]->next;
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_win, img.img, 0, 0);
	mlx_loop(data->mlx);
}


