/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:12:49 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 22:53:27 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	Draw all the lines and render all the pixel on the window.
*/
void	render(t_fdf *d)
{
	int	i;
	int	j;

	fill_black(d);
	i = -1;
	while (++i < d->map_ysize)
	{
		j = -1;
		while (++j < d->map_xsize)
		{
			if (i > 0)
				draw_line(d, d->map_end[i * d->map_xsize + j], \
						d->map_end[(i - 1) * d->map_xsize + j]);
			if (j > 0)
				draw_line(d, d->map_end[i * d->map_xsize + j], \
						d->map_end[i * d->map_xsize + j - 1]);
		}
	}
	mlx_put_image_to_window(d->mlx, d->window, d->img, 0, 0);
}
