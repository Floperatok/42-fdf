/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:12:49 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/28 16:11:51 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_drill(t_fdf *d, t_point point, t_point *pixel)
{
	double	midx;
	double	midy;

	midx = point.x - d->map_xsize / 2;
	midy = point.y - d->map_ysize / 2;
	pixel->x = (point.x * midy);
	pixel->y = (point.y * sin(midx));
}

t_point	get_pixel(t_fdf *d, t_point point)
{
	t_point	pixel;

	if (d->projection == 2)
		ft_drill(d, point, &pixel);
	if (d->projection == 1)
	{
		pixel.x = point.x;
		pixel.y = point.y;
		pixel.color = point.color;
	}
	else
	{
		pixel.x = point.x;
		pixel.y = point.y;
		pixel.color = point.color;
	}
	return (pixel);
}

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
				draw_line(d, get_pixel(d, d->map_end[i * d->map_xsize + j]), \
						get_pixel(d, d->map_end[(i - 1) * d->map_xsize + j]));
			if (j > 0)
				draw_line(d, get_pixel(d, d->map_end[i * d->map_xsize + j]), \
						get_pixel(d, d->map_end[i * d->map_xsize + j - 1]));
		}
	}
	mlx_put_image_to_window(d->mlx, d->window, d->img, 0, 0);
}
