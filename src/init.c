/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:49:04 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/23 16:53:31 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	Initialize data with all the mlx basic informations
*/
t_fdf	*ft_init(void)
{
	t_fdf	*data;
	
	data = malloc(sizeof(t_fdf));
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr_fd("Error: mlx_int() failed\n", 2);
		exit(EXIT_FAILURE);
	}
	data->window = mlx_new_window(data->mlx, SCREEN_W, SCREEN_H, "Fdf");
	if (!data->window)
	{
		ft_putstr_fd("Error: mlx_new_window() failed\n", 2);
		exit(EXIT_FAILURE);
	}
	data->img = mlx_new_image(data->mlx, SCREEN_W, SCREEN_H);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
				&data->line_length, &data->endian);
	data->map = NULL;
	data->A = 0.03;
	return (data);
}
