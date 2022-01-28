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
    params->zoom = 20;
    params->z = 0;
    params->shift_x = 300;
    params->shift_y = 300;
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
        ft_init_fdf(data);
        ft_get_dimensions(argv[1], data);
        ft_read_data(argv[1], data);
        ft_draw_map(data);
    }
    else
        printf("Please provide a valid path (490)\n");
    return (0);
}