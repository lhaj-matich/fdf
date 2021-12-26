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
	while (i < lines_number - 1)
	{
		line = ft_split(data[i], ' ');
		width = ft_count_width(data[i], ' ');
		matrix[i] = malloc(sizeof(int) * width);
		j = 0;
		while (j < width)
		{
			matrix[i][j] = ft_atoi(line[j]);
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
	int j;
	int width;

	i = 0;
	path = "test_maps/42.fdf";
	lines = ft_get_lines(path);
	words = ft_read_data(path);
	matrix = ft_create_matrix(words, lines);
	while (i < lines - 1)
	{
		j = 0;
		width = ft_count_width(words[i],' ');
		while (j < width - 1)
		{
			printf("%d ",matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
   	return (0);
}
