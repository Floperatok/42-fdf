/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:49:04 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/28 16:44:53 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	default_values(t_fdf *d)
{
	d->scale = (SCREEN_H - SCREEN_H / 1.5) / d->map_ysize * 2;
	d->projection = 1;
	d->origin.x = SCREEN_W / 2;
	d->origin.y = SCREEN_H / 2;
	d->map_end = malloc(sizeof(t_point) * (d->map_xsize * d->map_ysize + 1));
	d->line_thickness = 1;
	d->rotx = 0.50;
	d->roty = -0.25;
	d->rotz = 0.25;
	d->depth = 0.15;
	d->plan = 1;
	d->auto_rotation = 1;
}

/*
 *	Initialize data with all the mlx basic informations
*/
t_fdf	*ft_init(char **av)
{
	t_fdf	*d;

	d = malloc(sizeof(t_fdf));
	d->mlx = mlx_init();
	if (!d->mlx)
	{
		ft_putstr_fd("Error: mlx_int() failed\n", 2);
		exit(EXIT_FAILURE);
	}
	d->window = mlx_new_window(d->mlx, SCREEN_W, SCREEN_H, "Fdf");
	if (!d->window)
	{
		ft_putstr_fd("Error: mlx_new_window() failed\n", 2);
		exit(EXIT_FAILURE);
	}
	d->img = mlx_new_image(d->mlx, SCREEN_W, SCREEN_H);
	d->addr = mlx_get_data_addr(d->img, &d->bits_per_pixel, \
				&d->line_length, &d->endian);
	d->map = NULL;
	d->map_end = NULL;
	create_map(d, av[1]);
	default_values(d);
	return (d);
}
