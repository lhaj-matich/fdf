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


// void ft_draw_line(t_data *img, t_fdf *data ,float x, float y, float x1, float y1) 
// {
//     float x_step;
//     float y_step;
//     int max;

//     x *= data->zoom;
//     y *= data->zoom;
//     x1 *= data->zoom;
//     y1 *= data->zoom;

//     x_step = x1 - x;
//     x_step = y1 = y;

//     max = fmax(modf(x_step, &x_step), modf(y_step, &y_step));
//     x_step /= max;
//     y_step /= max;

//     while ((int)(x - x1) || (int)(y - y1))
//     {
//         my_mlx_pixel_put(img, x, y, 0x00FF0000);
//         x += x_step;
//         y += y_step;
//     }
// }

void ft_draw_line(t_data *img, t_fdf *data ,int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
	int zoom = data->zoom;
    int saved = X0;
    int alltitude;
	X0 *= zoom;
	X1 *= zoom;
	Y0 *= zoom;
	Y1 *= zoom;
    int dx = X1 - X0;
    int dy = Y1 - Y0;
 
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
    {
		// if (data->matrix[data->actual]->z > 0)
        // printf("%d ", alltitude);
		my_mlx_pixel_put(img, X, Y, 0x00FF0000);
        
          // put pixel at (X,Y)
		// else
		// 	my_mlx_pixel_put(img, X, Y, 0x00FF1000);
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
    }
}

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
