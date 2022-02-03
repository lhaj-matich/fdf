/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:11:46 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/03 15:37:32 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_xrotation(int *x, int *y, int *z, double angle)
{
	(void)(x);
	*y = *y * cos(angle) + *z * sin(angle);
	*z = -(*y) * sin(angle) + *z * (cos(angle));
}

void	ft_yrotation(int *x, int *y, int *z, double angle)
{
	(void)(y);
	*x = *x * cos(angle) + *z * sin(angle);
	*z = -(*x) * sin(angle) + *z * (cos(angle));
}

void	ft_zrotation(int *x, int *y, int *z, double angle)
{
	(void)(z);
	*x = *x * cos(angle) - *y * sin(angle);
	*y = (*x) * sin(angle) + *y * (cos(angle));
}

void	ft_translate_map(int *x, int *y, t_fdf *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}
