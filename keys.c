/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:01:39 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/05 13:17:02 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "draw.h"
#include "settings.h"
#include "utils.h"

void	esc_key(int key, t_fdf *param)
{
	if (key == 53)
		close_window(param);
}
