#include <math.h>
#include "fdf.h"
#include "points.h"
#include "draw.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y = -z + (previous_x + previous_y) * sin(0.523599);
}

void ft_draw_line(t_data *img, t_fdf *data ,float x, float y, float x1, float y1) 
{
    float x_step;
    float y_step;
    int max;


    ft_zoom(&x, &y, &x1, &y1, data);
    iso(&x, &y, data->matrix->z);
    iso(&x1, &y1, data->matrix->z);
    ft_shift(&x, &y, &x1, &y1, data);
    x_step = x1 - x;
    y_step = y1 - y;

    max = maxi(abs(x_step), abs(y_step));
    x_step /= max;
    y_step /= max;

    int color = (data->matrix->z) > 0 ? 0x00FF0000 : 0xffffff;
    while ((int)(x - x1) || (int)(y - y1))
    {
        my_mlx_pixel_put(img, x, y, color);
        x += x_step;
        y += y_step;
    }
}






// void ft_draw_line(t_data *img, t_fdf *data ,int X0, int Y0, int X1, int Y1)
// {

//     // Shiftting the figure
//     // Adding the zoom
// 	ft_zoom(&X0, &Y0, &X1, &Y1, data);
  

//     // calculate dx & dy
//     int dx = X1 - X0;
//     int dy = Y1 - Y0;
 
//     iso(&X0, &Y0,data->matrix->z);
//     iso(&X1, &Y1,data->matrix->z);
//     // calculate steps required for generating pixels
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//     // calculate increment in x & y for each steps
//     float Xinc = dx / (float) steps;
//     float Yinc = dy / (float) steps;
//     // Put pixel for each step
//     float X = X0;
//     float Y = Y0;
//       // Isometric
   
//     int color = (data->matrix->z) > 0 ? 0x00FF0000 : 0xffffff;
//     for (int i = 0; i <= steps; i++)
//     {
// 		// if (data->matrix[data->actual]->z > 0)
//         // printf("%d ", alltitude);
// 		my_mlx_pixel_put(img, X, Y, color);
        
//           // put pixel at (X,Y)
// 		// else
// 		// 	my_mlx_pixel_put(img, X, Y, 0x00FF1000);
//         X += Xinc;           // increment in x at each step
//         Y += Yinc;           // increment in y at each step
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
