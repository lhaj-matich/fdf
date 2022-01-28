#include <math.h>
#include <stdio.h>
#include <mlx.h>
#include "fdf.h"
#include "draw.h"
#include "points.h"
#include "keys.h"

void    ft_translate_map(int *x, int *y, t_fdf *data)
{  
    *x += data->shift_x;
    *y += data->shift_y;
}

void    ft_zoom_map(int *x, int *y, t_fdf *data)
{  
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

// Still need three functions that will handle the rotations.

// void ft_draw_line(t_data *img, t_fdf *data ,float x, float y, float x1, float y1) 
// {
//     float x_step;
//     float y_step;
//     int max;
//     int color;
//     int k1;
//     int k2;
//     int z1;
//     int z2;


//     k1 = y * data->width + x;
//     z1 = data->matrix[k1]->z;
//     k2 = y1 * data->width + x1;
//     z2 = data->matrix[k2]->z;

//     // printf("%d-%d\n",k1, k2);
//     ft_zoom(&x, &y, &x1, &y1, data);
//     iso(&x, &y, z1);
//     iso(&x1, &y1, z2);
//     ft_shift(&x, &y, &x1, &y1, data);
//     color = (z1 > 0) ? 0x00FF0000 : 0xfffffff;
//     x_step = x1 - x;
//     y_step = y1 - y;

//     max = maxi(fabsf(x_step), fabsf(y_step));
//     x_step /= max;
//     y_step /= max;

//     while ((int)(x - x1) || (int)(y - y1))
//     {
//         my_mlx_pixel_put(img, x, y, color);
//         x += x_step;
//         y += y_step;
//     }
// }

// White 0xfffffff
// Red 0x00FF0000



// void ft_draw_line(t_data *img, t_fdf *data,int x0, int y0, int x1, int y1)
// {
//     int dx,dy,sx,sy,err,e2;

//     int max;
//     int color;
//     int k1;
//     int k2;
//     int z1;
//     int z2;


//     k1 = y0 * data->width + x0;
//     z1 = data->matrix[k1]->z;
//     if (z1 > 0)
//         z1 += data->z;
//     k2 = y1 * data->width + x1;
//     z2 = data->matrix[k2]->z;
//     if (z2 > 0)
//         z2 += data->z;
//     ft_zoom_map(&x0, &y0, &x1, &y1, data);
//     ft_isometric(&x0, &y0, z1, data);
//     ft_isometric(&x1, &y1, z2, data);
//     ft_translate_map(&x0, &y0, &x1, &y1, data);

//     dx = abs(x1 - x0);
//     sx = x0 < x1 ? 1 : -1;
//     dy = -abs(y1 - y0);
//     sy = y0 < y1 ? 1 : -1;
//     err = dx + dy;

//     color = ft_get_color(k1, data);
//     while (1)
//     {
//         my_mlx_pixel_put(img, x0, y0, color);
//         if (x0 == x1 && y0 == y1)
//             break ;
//         e2 = 2*err;
//         if (e2 >= dy)
//         {
//             err += dy;
//             x0 += sx;
//         }
//         if (e2 <= dx)
//         {
//             err += dx;
//             y0 += sy;
//         }    
//     }
// }

// void ft_draw_line(t_data *img, t_fdf *data ,float x, float y, float x1, float y1) 
// {

//     // Shiftting the figure
//     // Adding the zoom
// 	ft_zoom(&x, &y, &x1, &y1, data);
  

//     // calculate dx & dy
//     int dx = x1 - x;
//     int dy = y1 - y;
 
//     iso(&x, &y,data->matrix->z);
//     iso(&x1, &y1,data->matrix->z);
//     // calculate steps required for generating pixels
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//     // calculate increment in x & y for each steps
//     float xinc = dx / (float) steps;
//     float yinc = dy / (float) steps;
//     // Put pixel for each step
//     float X = x;
//     float Y = y;
//       // Isometric
   
//     int color = (data->matrix->z) > 0 ? 0x00FF0000 : 0xffffff;
//     for (int i = 0; i <= steps; i++)
//     {
// 		    my_mlx_pixel_put(img, X, Y, color);
//          X += xinc;           // increment in x at each step
//          Y += yinc;           // increment in y at each step
//     }
// }

// void	ft_draw_line(t_data *img, t_fdf *data ,int x0,  int y0 , int x1, int y1)
// {
// 	x0 = x0 * data->zoom;
// 	x1 = x1 * data->zoom;
// 	y0 = y0 * data->zoom;
// 	y1 = y1 * data->zoom;

// 	int dx, dy, p , x ,y;

// 	dx = x1 - x0;
// 	dy = y1 - y0;

// 	x = x0;
// 	y = y0;

// 	p = 2 * dy - dx;
// 	while (x < x1)
// 	{
// 		if (p >= 0)
// 		{
// 			my_mlx_pixel_put(img, x, y, 0x00FF0000);
// 			 y = y + 1;
// 			 p = p + 2 * dy - 2 * dx;
// 		}
// 		else 
// 		{
// 			my_mlx_pixel_put(img,x, y, 0x00FF0000);
// 			p = p + 2 * dy;	
// 		}
// 		x = x + 1;
// 	}
// }
