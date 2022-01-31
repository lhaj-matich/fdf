/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sn4r7 <sn4r7@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:19:20 by ochoumou          #+#    #+#             */
/*   Updated: 2022/01/30 12:23:26 by sn4r7            ###   ########.fr       */
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

int	ft_convert_hex(char *hex)
{
	int i;
	int value;
	int length;
	long long decimal;
	long long base;

	decimal = 0;
	base = 1;
	i = 0;

	if (!hex)
		return (0);
	length = ft_strlen(hex);
	i = length - 1;
	while (i >= 0)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
		{
			decimal += (hex[i] - 48) * base;
			base *= 16;
		}
		else if (hex[i] >= 'A' && hex[i] <= 'F')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		else if (hex[i] >= 'a' && hex[i] <= 'f')
		{
			decimal += (hex[i] - 55) * base;
			base *= 16;
		}
		i--;
	}
	return (decimal);
}

int     ft_get_width(char *str, char sep)
{
        int i;
        int words_count;

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
	int 	fd;
	int 	height;
	int		width;

	height = 0;
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
		height++;
	}
	data->height = height;
	close(fd);
}

void	ft_read_data(char *path, t_fdf *data)
{
	// t_point *node;
	char	**points;
	char	**seperation;
	char	*line;
	int fd;
	int i;
	int k;
	int j;

	k = 0;
	i = 0;
	fd = open(path, O_RDONLY);
	data->matrix = (t_point **)malloc(sizeof(t_point *) * ((data->height * data->width) + 1));
	while (i < data->height)
	{
		j = 0;
		line = get_next_line(fd);
		points = ft_split(line, ' ');
		while (j < data->width)
		{
			seperation = ft_split(points[j],',');
			data->matrix[k++] = create_point(ft_atoi(seperation[0]) , ft_convert_hex(seperation[1]));
			j++;
		}
		i++;
	}
	close(fd);
}