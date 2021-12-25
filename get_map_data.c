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
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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
	return (data);
}

int main(void)
{
	char **words;
	char *path;
	int i;

	i = 0;
	path = "test_maps/42.fdf";
	words = ft_read_data(path);
	while (i < ft_get_lines(path))
	{
		printf("%s",words[i]);
		i++;
	}
   	return (0);
}
