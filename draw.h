/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:22:03 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/03 15:35:33 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	ft_draw(t_fdf *data, t_dot *a, t_dot *b);
void	ft_xrotation(int *x, int *y, int *z, double angle);
void	ft_yrotation(int *x, int *y, int *z, double angle);
void	ft_zrotation(int *x, int *y, int *z, double angle);
void	ft_translate_map(int *x, int *y, t_fdf *data);

#endif