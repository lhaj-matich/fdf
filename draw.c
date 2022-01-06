#include <math.h>
#include "fdf.h"
#include "points.h"
#include "draw.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color, t_fdf *fdf)
{
	char	*dst;
    if ((x >=0 || x <= fdf->height) && ( y >= 0  || y <= fdf->width))
    {
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
    }
}

int maxi(float a, float b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

void    ft_shift(float *x, float *y, float *x1, float *y1, t_fdf *data)
{  
    *x += data->shift * 10;
    *y += data->shift;
    *x1 += data->shift * 10;
    *y1 += data->shift;
}

void    ft_zoom(float *x, float *y, float *x1, float *y1, t_fdf *data)
{  
    *x *= data->zoom;
    *y *= data->zoom;
    *x1 *= data->zoom;
    *y1 *= data->zoom;
}

void iso(float *x, float *y, int z)
{
    int p_x;
    int p_y;

    p_x = *x;
    p_y = *y;
    *x = (p_x - p_y) * cos(0.523599);
    *y  = (p_x + p_y) * sin(0.523599) - z;
}

void ft_draw_line(t_data *img, t_fdf *data ,float x, float y, float x1, float y1) 
{
    float x_step;
    float y_step;
    int max;
    int color;
    int k1;
    int k2;
    int z1;
    int z2;


    k1 = y * data->width + x;
    z1 = data->matrix[k1]->z;
    k2 = y1 * data->width + x1;
    z2 = data->matrix[k2]->z;

    // printf("%d-%d\n",k1, k2);
    ft_zoom(&x, &y, &x1, &y1, data);
    iso(&x, &y, z1);
    iso(&x1, &y1, z2);
    ft_shift(&x, &y, &x1, &y1, data);
    color = (z1 > 0) ? 0x00FF0000 : 0xfffffff;
    x_step = x1 - x;
    y_step = y1 - y;

    max = maxi(fabsf(x_step), fabsf(y_step));
    x_step /= max;
    y_step /= max;

    while ((int)(x - x1) || (int)(y - y1))
    {
        my_mlx_pixel_put(img, x, y, color,data);
        x += x_step;
        y += y_step;
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
