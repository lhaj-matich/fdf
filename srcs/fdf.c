/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:19:10 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/08 19:06:50 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_image(t_data *img)
{
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->endian = 0;
	img->img = NULL;
	img->line_length = 0;
}

void	init_rot_angles(t_fdf *params)
{
	params->x_angle = 0;
	params->y_angle = 0;
	params->z_angle = 0;
}

void	ft_init_fdf(t_fdf *params)
{
	t_data	img;

	init_image(&img);
	init_rot_angles(params);
	params->iso = 1;
	params->z = 0;
	params->img = img;
	if (params->height < 20)
	{
		params->zoom = 35;
		params->shift_x = (W_WIDTH / 2) - (params->width * 10);
		params->shift_y = (W_HEIGHT / 2) - (params->height * 20);
	}
	else if (params->height < 100)
		params->zoom = 10;
	else
	{
		params->zoom = 2;
		params->shift_x = params->width / 1.5;
		params->shift_y = params->height / 1.5;
	}
	params->mlx = mlx_init();
	params->mlx_win = mlx_new_window(params->mlx, W_WIDTH, W_HEIGHT, "FDF");
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	t_read	*params;

	(void)argc;
	if (argv[1])
	{
		data = (t_fdf *)malloc(sizeof(t_fdf));
		if (!data)
			return (0);
		params = (t_read *)malloc(sizeof(t_read));
		if (!params)
			return (0);
		ft_get_dimensions(argv[1], data);
		ft_read_data(argv[1], data, params);
		ft_init_fdf(data);
		ft_draw_map(data);
	}
	else
		ft_app_error(3);
	return (0);
}