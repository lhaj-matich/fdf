/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:01:39 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/05 13:17:02 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	esc_key(int key, t_fdf *param)
{
	if (key == 53)
		close_window(param);
}

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

void	ft_toggle_parallel(int key, t_fdf *param)
{
	if (key == KEYP)
	{
		if (param->iso == 1)
			param->iso = 0;
		else
			param->iso = 1;
	}
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
