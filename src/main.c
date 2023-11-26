/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:22 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/26 11:00:21 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	user_input(int keycode, t_fdf *data)
{
	if (keycode == 65307)
		end(data);
	else if (keycode == 65362)
		data->origin.y -= 1;
	else if (keycode == 65363)
		data->origin.x += 1;
	else if (keycode == 65364)
		data->origin.y += 1;
	else if (keycode == 65361)
		data->origin.x -= 1;
	else if (keycode == 65453 && data->scale > 1)
		data->scale -= 1;
	else if (keycode == 65451)
		data->scale += 1;
	else
		ft_printf("keycode = %d\n", keycode);
	render(data);
	return (0);
}

int	fdf(t_fdf *data)
{
	render(data);
	mlx_hook(data->window, 17, 0L, &end, data);
	mlx_hook(data->window, 2, 1L << 0, &user_input, data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

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
	data = ft_init();
	create_map(data, av[1]);
	fdf(data);
}
