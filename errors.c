/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochoumou <ochoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:17:42 by ochoumou          #+#    #+#             */
/*   Updated: 2022/02/03 18:00:01 by ochoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "settings.h"

void	ft_app_error(int error_code)
{
	if (error_code == 1)
		ft_putstr_fd("Invalid Map: Empty Map\n", 2);
	else if (error_code == 2)
		ft_putstr_fd("Invalid Map: The map is not valid\n", 2);
	else if (error_code == 3)
		ft_putstr_fd("Please provide a valid path (490)\n", 2);
	exit(ERROR_STATUS);
}
