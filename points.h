/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:56:52 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/03 15:14:41 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTS_H
# define POINTS_H

# include <stdlib.h>

typedef struct s_point {
	int	color;
	int	z;
}	t_point;

t_point	*init_point(int alltitude, int color);

#endif