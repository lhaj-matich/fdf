#include "fdf.h"
#ifndef GET_MAP_DATA_H
#define GET_MAP_DATA_H

int     ft_get_width(char *str, char sep);
void	ft_get_dimensions(char *path, t_fdf *data);
int     ft_get_width(char *str, char sep);
int	ft_check(char *str);
void	ft_read_data(char *path, t_fdf *data);

#endif