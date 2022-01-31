#include "get_map_data.h"
#include "fdf.h" 
#include "draw.h"
#include "points.h"
#include "settings.h"
#include <mlx.h>
#include <stdio.h>

int ft_init_fdf(t_fdf *params)
{
    t_data img;

    params->img = img;
    if (params->height > 50)
        params->zoom = 2;
    else if (params->height > 20)
        params->zoom = 10;
    else if (params->height < 20)
        params->zoom = 30;
    params->z = 0;
    params->x_angle = 0;
    params->y_angle = 0;
    params->z_angle = 0;
    if (params->height < 50)
        params->shift_x = (W_WIDTH / 2) - (params->width * 10);
    else if (params->height < 50)
        params->shift_y = (W_HEIGHT / 2) - (params->height * 20);
    else 
    {
         params->shift_x = 10;
         params->shift_y = 10;
    }
    params->mlx = mlx_init();
    params->mlx_win = mlx_new_window(params->mlx, W_WIDTH, W_HEIGHT , "FDF");
}

int main(int argc, char **argv)
{
    t_fdf *data;
    
    if (argv[1])
    {
        data = (t_fdf *)malloc(sizeof(t_fdf));
        if (!data)
            return (0);
        ft_get_dimensions(argv[1], data);
        ft_read_data(argv[1], data);
        ft_init_fdf(data);
        ft_draw_map(data);
    }
    else
        printf("Please provide a valid path (490)\n");
    return (0);
}