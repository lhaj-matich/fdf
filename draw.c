#include "draw.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_line(t_data *img, int x0,  int y0 , int x1, int y1)
{
	int dx, dy, p , x ,y;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;

	p = 2 * dy - dx;
	while (x < x1)
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			 y = y + 1;
			 p = p + 2 * dy - 2 * dx;
		}
		else 
		{
			my_mlx_pixel_put(img,x, y, 0x00FF0000);
			p = p + 2 * dy;	
		}
		x = x + 1;
	}
}
