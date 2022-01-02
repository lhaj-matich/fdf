#include <maths.h>

void	ft_draw_line(int x0,  int y0 , int x1, int y1)
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
			// mlx_put_pixcel(x,y,7);
			 y = y + 1;
			 p = p + 2 * dy - 2 * dx;
		}
		else 
		{
			// mlx_put_pixcel(x,y,7);
			p = p + 2 * dy;	
		}
		x = x + 1;
	}
}
