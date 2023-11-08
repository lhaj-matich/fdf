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

#include <math.h>
#include <mlx.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "get_next_line.h"

# define W_HEIGHT 1120
# define W_WIDTH 1250

// MACOS KEYS
// # define KEYDOWN 125
// # define KEYUP 126
// # define KEYLEFT 123
// # define KEYRIGHT 124
// # define KEYE 14
// # define KEYQ 12
// # define KEYX 7
// # define KEYY 16
// # define KEYZ 6
// # define KEYW 13
// # define KEYS 1
// # define KEYP 35

// LINUX KEYS

# define KEYDOWN 65364
# define KEYUP 65362
# define KEYLEFT 65361
# define KEYRIGHT 65363
# define KEYE 101
# define KEYQ 113
# define KEYX 120
# define KEYY 121
# define KEYZ 122
# define KEYW 119
# define KEYS 115
# define KEYP 112

# define ERROR_STATUS 1

typedef struct s_point {
	int	color;
	int	z;
}	t_point;

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

// Parse map
void	ft_get_dimensions(char *path, t_fdf *data);
int		ft_get_width(char *str, char sep);
int		ft_check(char *str);
void	ft_read_data(char *path, t_fdf *data, t_read *params);
int		ft_compare(int a, int b);
void	ft_app_error(int error_code);
int		close_window(t_fdf *data);
int		ft_get_color(int index, t_fdf *data);
void	ft_draw(t_fdf *data, t_dot *a, t_dot *b);
void	ft_xrotation(int *x, int *y, int *z, double angle);
void	ft_yrotation(int *x, int *y, int *z, double angle);
void	ft_zrotation(int *x, int *y, int *z, double angle);
int		handle_keys(int key, t_fdf *param);
void	esc_key(int key, t_fdf *param);
void	ft_translate(int key, t_fdf *param);
void	ft_translate_map(int *x, int *y, t_fdf *data);
void	ft_toggle_parallel(int key, t_fdf *param);
void	ft_zoom(int key, t_fdf *param);
void	ft_increase_alltitude(int key, t_fdf *param);
void	ft_rotate(int key, t_fdf *param);
int		is_hexa(char c);

t_point	*init_point(int alltitude, int color);

// Libft

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(char *str);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char *s, char c);

#endif