/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:25:05 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/03 15:25:39 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_DATA_H
# define GET_MAP_DATA_H
# include "fdf.h"

int		ft_get_width(char *str, char sep);
void	ft_get_dimensions(char *path, t_fdf *data);
int		ft_get_width(char *str, char sep);
int		ft_check(char *str);
void	ft_read_data(char *path, t_fdf *data, t_read *params);

#endif