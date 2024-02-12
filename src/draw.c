/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:44:00 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 22:40:45 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
 *	Write on the image a pixel of the color of your choice
 *		on the given coordinates.
*/
void	ft_pixel_put(t_fdf *d, t_point pixel)
{
	char	*dst;
	int		x;
	int		y;

	x = pixel.x;
	y = pixel.y;
	if (x > 0 && x < SCREEN_W && y > 0 && y < SCREEN_H)
	{
		dst = (char *)d->addr + (y * d->line_length + x * \
			(d->bits_per_pixel / 8));
		*(unsigned int *)dst = pixel.color;
	}
}

/*
 *	Fill the entire image with black pixels.
 *	This function is meant to reset the screen in black, overwriting the
 *		previous frame, ready for drawing the next frame.
*/
void	fill_black(t_fdf *d)
{
	t_point	pixel;
	int		i;
	int		j;

	i = -1;
	while (++i < SCREEN_H)
	{
		j = -1;
		while (++j < SCREEN_W)
		{
			pixel.x = j;
			pixel.y = i;
			pixel.color = 0x000000;
			ft_pixel_put(d, pixel);
		}
	}
}

/*
 *	Manage the thinckness of the line by changing the size of the pixel.
*/
static void	draw_line_thickness(t_fdf *d, t_point pixel)
{
	int		i;
	t_point	thinckness;

	i = d->line_thickness;
	while (--i > 0)
	{
		thinckness.color = pixel.color;
		thinckness.x = pixel.x + i;
		thinckness.y = pixel.y;
		ft_pixel_put(d, thinckness);
		thinckness.x = pixel.x - i;
		thinckness.y = pixel.y;
		ft_pixel_put(d, thinckness);
		thinckness.x = pixel.x;
		thinckness.y = pixel.y + i;
		ft_pixel_put(d, thinckness);
		thinckness.x = pixel.x;
		thinckness.y = pixel.y - i;
		ft_pixel_put(d, thinckness);
	}
}

/*
 *	Draw a line pixel by pixel from point a to point b.
*/
void	draw_line(t_fdf *d, t_point a, t_point b)
{
	t_point	vector;
	t_point	pixel;
	double	distance;
	int		color_distance;
	double	i;

	color_distance = a.color - b.color;
	vector.x = b.x - a.x;
	vector.y = b.y - a.y;
	distance = fabs(a.x - b.x) + fabs(a.y - b.y);
	i = 0;
	while (++i < distance)
	{
		pixel.x = a.x + (vector.x / distance) * i;
		pixel.y = a.y + (vector.y / distance) * i;
		pixel.color = a.color + color_distance / 2;
		pixel.color = compute_color(a.color, b.color, i, distance);
		ft_pixel_put(d, pixel);
		draw_line_thickness(d, pixel);
	}
}
