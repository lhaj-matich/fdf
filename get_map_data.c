/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:19:20 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/03 15:55:27 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"
#include "points.h"
#include "draw.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

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

int	hex(char *str)
{
	int		i;
	int		result;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	while (str[i] == '0' || str[i] == 'x')
		i++;
	while (str[i])
	{
		result *= 16;
		result = result + is_hexa(str[i]);
		i++;
	}
	return (result);
}

int	ft_get_width(char *str, char sep)
{
	int	i;
	int	words_count;

	i = 0;
	words_count = 0;
	if (str[i] != sep)
	{
				words_count += 1;
				i += 1;
	}
	while (str[i] != '\0')
	{
		if (str[i] != sep && str[i] != '\n' && str[i - 1] == sep)
			words_count++;
		i++;
	}
	return (words_count);
}

void	ft_get_dimensions(char *path, t_fdf *data)
{
	char	*line;
	int		fd;

	data->height = 0;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		ft_app_error(1);
	data->width = ft_get_width(line, ' ');
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (data->width != ft_get_width(line, ' '))
				ft_app_error(2);
		}
		data->height++;
	}
	close(fd);
}

void	ft_read_data(char *path, t_fdf *data, t_read *p)
{
	int	size;

	size = data->height * data->width;
	p->k = 0;
	p->i = 0;
	p->fd = open(path, O_RDONLY);
	data->matrix = (t_point **)malloc(sizeof(t_point *) * (size + 1));
	while (p->i < data->height)
	{
		p->j = 0;
		p->points = ft_split(get_next_line(p->fd), ' ');
		while (p->j < data->width)
		{
			p->sep = ft_split(p->points[p->j], ',');
			data->matrix[p->k] = init_point(ft_atoi(p->sep[0]), hex(p->sep[1]));
			p->j++;
			p->k++;
		}
		p->i++;
	}
	close(p->fd);
}
