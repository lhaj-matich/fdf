/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:46:04 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/05 11:58:22 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fdf.h"

int		ft_compare(int a, int b);
void	ft_app_error(int error_code);
int		is_hexa(char c);
int		close_window(t_fdf *data);
int		ft_get_color(int index, t_fdf *data);

#endif