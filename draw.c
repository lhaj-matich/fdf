#include <math.h>
#include <stdio.h>
#include "fdf.h"
#include "draw.h"
#include "points.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
    if ((x >=0 && x < 960) && ( y >= 0  && y < 780))
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

// int maxi(float a, float b)
// {
//     if (a > b)
//         return (a);
//     else
//         return (b);
// }

void    ft_shift(int *x, int *y, int *x1, int *y1, t_fdf *data)
{  
    *x += data->shift_x;
    *y += data->shift_y;
    *x1 += data->shift_x;
    *y1 += data->shift_y;
}

void    ft_zoom(int *x, int *y, int *x1, int *y1, t_fdf *data)
{  
    *x *= data->zoom;
    *y *= data->zoom;
    *x1 *= data->zoom;
    *y1 *= data->zoom;
}

void iso(int *x, int *y, int z, t_fdf *data)
{
    int p_x;
    int p_y;

    p_x = *x;
    p_y = *y;
    *x = (p_x - p_y) * cos(0.523599);
    *y  = (p_x + p_y) * sin(0.523599) - z;
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

int  get_color(int k, t_fdf *data)
{
    int color;
    int alltitude;

    color = data->matrix[k]->color;
    alltitude = data->matrix[k]->z;
    if (color > 0) 
        return color;
    else if (alltitude > 0 && color == 0)
        return (0x00FF0000);
    else
        return (0xfffffff);
}

void ft_draw_line(t_data *img, t_fdf *data,int x0, int y0, int x1, int y1)
{
    int dx,dy,sx,sy,err,e2;

    int max;
    int color;
    int k1;
    int k2;
    int z1;
    int z2;


    k1 = y0 * data->width + x0;
    z1 = data->matrix[k1]->z;
    if (z1 > 0)
        z1 += data->z;
    k2 = y1 * data->width + x1;
    z2 = data->matrix[k2]->z;
    if (z2 > 0)
        z2 += data->z;
    ft_zoom(&x0, &y0, &x1, &y1, data);
    iso(&x0, &y0, z1, data);
    iso(&x1, &y1, z2, data);
    ft_shift(&x0, &y0, &x1, &y1, data);

    dx = abs(x1 - x0);
    sx = x0 < x1 ? 1 : -1;
    dy = -abs(y1 - y0);
    sy = y0 < y1 ? 1 : -1;
    err = dx + dy;

    color = get_color(k1, data);
    while (1)
    {
        my_mlx_pixel_put(img, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break ;
        e2 = 2*err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }    
    }
}

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
