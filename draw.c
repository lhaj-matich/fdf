/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:10:55 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/03 18:05:15 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "fdf.h"
#include "draw.h"
#include "points.h"
#include "keys.h"
#include "settings.h"

void	ft_zoom_map(int *x, int *y, t_fdf *data)
{
	if (data->zoom < 2)
		data->zoom = 1;
	*x *= data->zoom;
	*y *= data->zoom;
}

void	ft_isometric(int *x, int *y, int z)
{
	int	p_x;
	int	p_y;

	p_x = *x;
	p_y = *y;
	*x = (p_x - p_y) * cos(0.523599);
	*y = (p_x + p_y) * sin(0.523599) - z;
}

int	ft_get_color(int index, t_fdf *data)
{
	int	color;
	int	alltitude;

	color = data->matrix[index]->color;
	alltitude = data->matrix[index]->z;
	if (color > 0)
		return (color);
	else if (alltitude > 0 && color == 0)
		return (0x00FF0000);
	else
		return (0xfffffff);
}

t_dot	*ft_prep(t_fdf *data, int x, int y)
{
	t_dot	*point;
	int		index;
	int		alltitude;

	point = malloc(sizeof(t_dot));
	if (!point)
		return (NULL);
	index = y * data->width + x;
	alltitude = data->matrix[index]->z;
	if (alltitude > 0)
		alltitude += data->z;
	ft_zoom_map(&x, &y, data);
	ft_isometric(&x, &y, alltitude);
	ft_xrotation(&x, &y, &alltitude, data->x_angle);
	ft_yrotation(&x, &y, &alltitude, data->y_angle);
	ft_zrotation(&x, &y, &alltitude, data->z_angle);
	ft_translate_map(&x, &y, data);
	point->x = x;
	point->y = y;
	point->color = ft_get_color(index, data);
	return (point);
}

void	ft_draw_map(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	data->img.img = mlx_new_image(data->mlx, W_WIDTH, W_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				ft_draw(data, ft_prep(data, x, y), \
				ft_prep(data, x + 1, y));
			if (y < data->height - 1)
				ft_draw(data, ft_prep(data, x, y), ft_prep(data, x, y + 1));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	mlx_hook(data->mlx_win, 17, 0, close_window, data);
	mlx_key_hook(data->mlx_win, handle_keys, data);
	mlx_loop(data->mlx);
}
