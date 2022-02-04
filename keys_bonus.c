/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:01:39 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/04 19:44:30 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "draw.h"
#include "settings.h"

void	ft_translate(int key, t_fdf *param)
{
	if (key == KEYDOWN)
		param->shift_y += 20;
	else if (key == KEYUP)
		param->shift_y -= 20;
	else if (key == KEYLEFT)
		param->shift_x -= 20;
	else if (key == KEYRIGHT)
		param->shift_x += 20;
}

void	ft_zoom(int key, t_fdf *param)
{
	if (key == KEYQ)
	{
		param->zoom += 1;
		param->shift_x += 2;
		param->shift_y += 2;
	}
	else if (key == KEYE)
	{
		param->zoom -= 1;
		param->shift_x -= 2;
		param->shift_y -= 2;
	}
}

void	ft_increase_alltitude(int key, t_fdf *param)
{
	if (key == KEYW)
		param->z += 2;
	else if (key == KEYS)
		param->z -= 2;
}

void	ft_rotate(int key, t_fdf *param)
{
	if (key == KEYX)
		param->x_angle += 0.2;
	else if (key == KEYY)
		param->y_angle += 0.2;
	else if (key == KEYZ)
		param->z_angle += 0.2;
}

int	handle_keys(int key, t_fdf *param)
{
	ft_translate(key, param);
	ft_zoom(key, param);
	ft_rotate(key, param);
	ft_increase_alltitude(key, param);
	mlx_clear_window(param->mlx, param->mlx_win);
	mlx_destroy_image(param->mlx, param->img.img);
	ft_draw_map(param);
	return (0);
}
