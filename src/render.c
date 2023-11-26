/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:12:49 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/26 11:01:27 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render(t_fdf *data)
{
	int		i;

	fill_black(data);
	i = -1;
	while (++i < data->map_xsize * data->map_ysize)
	{
		ft_pixel_put(data, data->map[i].x * data->scale + data->origin.x, \
					data->map[i].y * data->scale + data->origin.y, WHITE);
	}
	mlx_put_image_to_window(data->mlx, data->window, data->img, 0, 0);
}
