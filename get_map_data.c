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
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int     ft_count_width(char *str, char sep)
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
                if (str[i] != sep && str[i - 1] == sep)
                        words_count++;
                i++;
        }
        return (words_count);
}

int ft_check(char *str) 
{
	int i;

	i = 0;
	while (str[i])
	{	
		if (str[i] == ',')
			return (1);
		i++;
	}
	return (0);
}

int	ft_get_lines(char *path)
{
	char *line;
	int number_of_lines;
	int fd;

	fd = open(path, O_RDONLY);
	number_of_lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		number_of_lines++;
		line = get_next_line(fd);
	}
	close(fd);
	return (number_of_lines);
}

char	**ft_read_data(char *path)
{
	char **data;
	int lines;
	int fd;
	int i;
	int status;

	i = 0;
	lines = ft_get_lines(path);
	fd = open(path, O_RDONLY);
	data = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!data)
		return (NULL);
	while (i < lines)
	{
		data[i] = get_next_line(fd);
		i++;
	}
	data[i] = NULL;
	close(fd);
	return (data);
}

int	**ft_create_matrix(char **data,int lines_number, int width)
{
	char **line;
	char **point_info;
	int **matrix;
	int **colors;
	int i;
	int j;

	i = 0;
 	colors = (int **)malloc(sizeof(int *) * (lines_number + 1));
	matrix = (int **)malloc(sizeof(int *) * (lines_number + 1));
	if (!matrix || !colors)
		return (NULL);
	while (i < lines_number - 1)
	{
		j = 0;
		colors[i] = (int *)malloc(sizeof(int) * width);
		matrix[i] = (int *)malloc(sizeof(int) * width);
		line = ft_split(data[i], ' ');
		while (j < width)
		{
			if (ft_strlen(line[j]) > 1)
			{
				point_info = ft_split(line[j], ',');
				colors[i][j] = ft_convert_hex(point_info[1]);
				matrix[i][j] = ft_atoi(point_info[0]);
			}
			else
			{
				printf("Not a commas");
				matrix[i][j] = ft_atoi(line[j]);
				colors[i][j] = 0;
			}
			j++;
		}
		i++;
	}
	return (colors);
}

int main(void)
{
	char **words;
	int	**matrix;
	char *path;
	int status;
	int lines;
	int nothing;
	int i;
	int j;
	int width;

	i = 0;

	// t_point *node;
	// t_point	*head;
	// t_point *tmp;

	// head = NULL;

	// while (i < 20)
	// {
	// 	node = create_point(i,15 + i);
	// 	head = insert_point(head, node);
	// 	i++;
	// }
	// while (head != NULL)
	// {
	// 	printf("Color: %d\n", head->color);
	// 	printf("Alltitude: %d\n",head->z);
	// 	head = head->next;
	// }
	path = "test_maps/elem-col.fdf";
	lines = ft_get_lines(path);
	words = ft_read_data(path);
	width = ft_count_width(words[i],' ');
	matrix = ft_create_matrix(words, lines, width);
	// while (i < lines - 1)
	// {
	// 	j = 0;
	// 	width = ft_count_width(words[i],' ');
	// 	while (j < width)
	// 	{
	// 		if (matrix[i][j])
	// 		{
	// 			 printf("%d ",matrix[i][j]);
	// 			 j++;
	// 		}
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
   	return (0);
}
