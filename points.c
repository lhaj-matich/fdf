/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:58:46 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/03 15:01:14 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

t_point	*init_point(int alltitude, int color)
{
	t_point	*point;

	point = malloc(sizeof(t_point));
	if (!point)
		return (NULL);
	point->z = alltitude;
	point->color = color;
	return (point);
}
