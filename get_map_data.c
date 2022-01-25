/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:19:20 by ochoumou          #+#    #+#             */
/*   Updated: 2021/12/26 15:08:28 by ochoumou         ###   ########.fr       */
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
	data->width = ft_get_width(line, ' ');
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line)
		{
			if (data->width != ft_get_width(line, ' '))
			{
				printf("Invalid Map: The map is incomplete\n");
				exit(0);
			}
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
	int width;
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
			// The line bellow could be used for normination purpuses.
			// node = create_point(ft_atoi(seperation[0]), ft_convert_hex(seperation[1]));
			int z = ft_atoi(seperation[0]);
			int color = ft_convert_hex(seperation[1]);
			data->matrix[k] = create_point(z , color);
			j++;
			k++;
		}
		i++;
	}
	close(fd);
}

/// Tasks:

// *The next idea: is to allocate a table of sturct each index contains a color and alltitude of the corresponding point.
// *Looking into how key bindings working in the minilibx library.

// This is just a bunch of dead code.
// int	**ft_create_matrix(char **data,int lines_number, int width)
// {
// 	char **line;
// 	char **point_info;
// 	int **matrix;
// 	int **colors;
// 	int i;
// 	int j;

// 	i = 0;
//  	colors = (int **)malloc(sizeof(int *) * (lines_number + 1));
// 	matrix = (int **)malloc(sizeof(int *) * (lines_number + 1));
// 	if (!matrix || !colors)
// 		return (NULL);
// 	while (i < lines_number - 1)
// 	{
// 		j = 0;
// 		colors[i] = (int *)malloc(sizeof(int) * width);
// 		matrix[i] = (int *)malloc(sizeof(int) * width);
// 		line = ft_split(data[i], ' ');
// 		while (j < width)
// 		{
// 			if (ft_check(line[j]))
// 			{
// 				point_info = ft_split(line[j], ',');
// 				matrix[i][j] = ft_atoi(point_info[0]);
// 				colors[i][j] = ft_convert_hex(point_info[1]);
// 			}
// 			else
// 			{
// 				matrix[i][j] = ft_atoi(line[j]);
// 				colors[i][j] = 0;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (colors);
// }
