/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:19:20 by ochoumou          #+#    #+#             */
/*   Updated: 2021/12/25 02:51:02 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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

int	ft_get_lines(char *path)
{
	char *line;
	int number_of_lines;
	int fd;

	fd = open(path, O_RDONLY);
	number_of_lines = 0;
	while (line != NULL)
	{
		line = get_next_line(fd);
		number_of_lines++;
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

	i = 0;
	fd = open(path, O_RDONLY);
	lines = ft_get_lines(path);
	data = (char **)malloc(sizeof(char *) * (lines + 1));
	if (!data)
		return (NULL);
	while (i < lines)
	{
		data[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (data);
}

int	**ft_create_matrix(char **data, int lines_number)
{
	char **line;
	int **matrix;
	int width;
	int i;
	int j;

	i = 0;
	matrix = (int **)malloc(sizeof(int *) * (lines_number + 1));
	if (!matrix)
		return (NULL);
	
	// line = ft_split(data[0], ' ');
	// printf("%c", line[0][0]);
	
	// while (i < 10)
	// {
	// 	printf("%s", line[i]);
	// 	i++;
	// }
	while (i < lines_number - 1)
	{
		// printf("%s\n",data[i]);
		line = ft_split(data[i], ' ');
		width = ft_count_width(data[i], ' ');
		matrix[i] = malloc(sizeof(int) * width);
		j = 0;
		while (j < width)
		{
			matrix[i][j] = ft_atoi(line[i]);
			j++;
		}
		i++;
	}
	return (matrix);
}

int main(void)
{
	char **words;
	int	**matrix;
	char *path;
	int lines;
	int nothing;
	int i;

	i = 0;
	path = "test_maps/42.fdf";
	lines = ft_get_lines(path);
	words = ft_read_data(path);
	matrix = ft_create_matrix(words, lines);
	printf("%d\n",matrix[0][0]);
   	return (0);
}
