/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:17:42 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/04 20:03:53 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "settings.h"
#include "fdf.h"

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

int	ft_compare(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	ft_app_error(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd("Invalid Map: Empty Map (492)\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Invalid Map: The map is not valid (491)\n", 2);
	else if (error_code == 3)
		ft_putstr_fd("Please provide a valid path (490)\n", 2);
	exit(ERROR_STATUS);
}

int	is_hexa(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	return (c - 48);
}

int	close_window(t_fdf *data)
{
	mlx_destroy_image(data->mlx, data->img.img);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}
