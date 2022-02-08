/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:23:13 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/08 18:19:21 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "points.h"

typedef struct s_dot {
	int	x;
	int	y;
	int	color;
}	t_dot;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_bresenham {
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_bresenham;

typedef struct s_read {
	int		i;
	int		j;
	int		k;
	int		fd;
	int		size;
	char	**sep;
	char	**points;
}	t_read;

typedef struct s_fdf
{
	t_point	**matrix;
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		z;
	int		k;
	int		iso;
	double	x_angle;
	double	y_angle;
	double	z_angle;
	t_data	img;
}	t_fdf;

void	ft_draw_map(t_fdf *data);

#endif