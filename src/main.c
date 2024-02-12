/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:22 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 22:47:36 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	Auto rotation handling.
*/
int	spinning(t_fdf *d)
{
	if (d->auto_rotation)
	{
		d->roty += 0.01;
		apply_change(d);
		render(d);
	}
	return (0);
}

int	fdf(t_fdf *d)
{
	apply_change(d);
	render(d);
	mlx_hook(d->window, 17, 0L, &end, d);
	mlx_hook(d->window, 2, 1L << 0, &user_input, d);
	mlx_loop_hook(d->mlx, &spinning, d);
	mlx_loop(d->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*d;

	if (ac > 2)
	{
		ft_putstr_fd("Error: Too many arguments where given to ./fdf\n", 2);
		exit(EXIT_FAILURE);
	}
	if (ac < 2)
	{
		ft_putstr_fd("Usage: ./fdf [FILE]\nExemple: './fdf 42.fdf'\n", 2);
		exit(EXIT_FAILURE);
	}
	d = ft_init(av);
	if (!d->map_end)
		error_handler(d);
	fdf(d);
}
