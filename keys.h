/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:12:46 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/05 13:17:05 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

int		handle_keys(int key, t_fdf *param);
int		close_window(t_fdf *data);
void	esc_key(int key, t_fdf *param);
void	ft_translate(int key, t_fdf *param);
void	ft_toggle_parallel(int key, t_fdf *param);
void	ft_zoom(int key, t_fdf *param);
void	ft_increase_alltitude(int key, t_fdf *param);
void	ft_rotate(int key, t_fdf *param);

#endif