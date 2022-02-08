/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:19:20 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/08 18:15:09 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "utils.h"
#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"
#include "points.h"
#include "draw.h"

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

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
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
		free(line);
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
	char	*line;

	p->k = 0;
	p->i = 0;
	p->size = data->height * data->width;
	p->fd = open(path, O_RDONLY);
	data->matrix = (t_point **)malloc(sizeof(t_point *) * (p->size + 1));
	while (p->i < data->height)
	{
		p->j = 0;
		line = get_next_line(p->fd);
		p->points = ft_split(line, ' ');
		while (p->j < data->width)
		{
			p->sep = ft_split(p->points[p->j], ',');
			data->matrix[p->k] = init_point(ft_atoi(p->sep[0]), hex(p->sep[1]));
			p->j++;
			p->k++;
			free_tab(p->sep);
		}
		free_tab(p->points);
		free(line);
		p->i++;
	}
	close(p->fd);
}
