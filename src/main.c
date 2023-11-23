/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:22 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/23 16:55:09 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	user_input(int keycode, t_fdf *data)
{

	if (keycode == 65307)
		end(data);
	else if (keycode == 32)
		data->A += 0.3;
	else
		ft_printf("keycode = %d\n", keycode);
	fill_black(data, SCREEN_W, SCREEN_H);
	draw_donut(data, sin(data->A), 0.03);
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
	return (0);
}

int	fdf(t_fdf *data)
{
	mlx_hook(data->window, 17, 0L, &end, data);
	mlx_hook(data->window, 2, 1L<<0, &user_input, data);
	mlx_loop(data->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_fdf	*data;

	(void)av;
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
	fdf(data);
}
