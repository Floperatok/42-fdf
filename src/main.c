/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:27:22 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/21 14:22:33 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw(t_fdf *data)
{
	int	i;

	i = 0;
	while (++i < 50)
		ft_pixel_put(data, i, i, 0x00FF0000);
}

int	end(t_fdf *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	t_fdf	data;

	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 1920, 1080, "Hello world!");
	// data.img = mlx_new_image(data.mlx, 1920, 1080);
	// data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
								// &data.endian);
	// ft_printf("%s", data.addr);
	// draw(&data);
	// mlx_hook(data.window, 17, 0, &end, &data);
	// mlx_put_image_to_window(data.mlx, data.window, data.img, 0, 0);
	mlx_loop(data.mlx);
}