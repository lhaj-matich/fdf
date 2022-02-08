/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:30:15 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/08 12:58:43 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "draw.h"
#include "points.h"
#include "settings.h"
#include "utils.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x < W_WIDTH) && (y >= 0 && y < W_HEIGHT))
	{
		dst = data->addr + (y * data->line_length + x \
		* (data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

t_bresenham	*ft_init_bresenham(t_dot *a, t_dot *b)
{
	t_bresenham	*params;

	params = malloc(sizeof(t_bresenham));
	if (!params)
		return (NULL);
	params->dx = abs(b->x - a->x);
	params->sx = ft_compare(a->x, b->x);
	params->dy = -abs(b->y - a->y);
	params->sy = ft_compare(a->y, b->y);
	params->err = params->dx + params->dy;
	return (params);
}

void	ft_draw(t_fdf *data, t_dot *a, t_dot *b)
{
	t_bresenham	*params;

	params = ft_init_bresenham(a, b);
	while (1)
	{
		my_mlx_pixel_put(&data->img, a->x, a->y, a->color);
		if (a->x == b->x && a->y == b->y)
			break ;
		params->e2 = 2 * params->err;
		if (params->e2 >= params->dy)
		{
			params->err += params->dy;
			a->x += params->sx;
		}
		if (params->e2 <= params->dx)
		{
			params->err += params->dx;
			a->y += params->sy;
		}
	}
	free(params);
	free(a);
	free(b);
}
