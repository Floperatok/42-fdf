/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:44:00 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/28 17:31:35 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

/*
 *	Write on the image a pixel of the color of your choice
 *		on the given coordinates.
 *	Arguments:
 *		t_fdf *d		: The main d structure.
 *		t_point	pixel	: The point with the coordinates of the pixel.
 *		int color		: The color in the format 0xAARRGGBB.
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
 *	Arguments:
 *		t_fdf *d	: The main d structure.
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
 *	Arguments:
 *		t_fdf *d	: The main data structure.
 *		t_point *a	: The point a.
 *		t_point *a	: The point b.
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

// a.x=1 ; a.y=2    b.x=4 ; b.y=-1
/*
void	draw_donut(t_fdf *d, double A_tmp, double B_tmp)
{
	double	pi = 3.14159265;

	double	A = sin(A_tmp);
	double	B = sin(B_tmp);

	int		height = 500;
	int		width = 500;
	
	double theta_spacing = 0.07;
	double phi_spacing = 0.02;
	
	double	R1 = 1;
	double	R2 = 2;
	double	K2 = 5;
	double	K1 = width * K2 * 3 / (8 * (R1 + R2));

	double	cosA = cos(A);
	double	cosB = cos(B);
	double	sinA = sin(A);
	double	sinB = sin(B);

	char	output[height][width];
	double	zbuffer[height][width];
	int		i = -1;
	while (++i < height)
	{
		int		j = -1;
		while (++j < width)
		{
			output[i][j] = ' ';
			zbuffer[i][j] = 0;
		}
	}
	double theta = 0;
	while (theta < 2 * pi)
	{
		double	costheta = cos(theta);
		double	sintheta = sin(theta);

		double	phi = 0;
		while (phi < 2 * pi)
		{
			double	cosphi = cos(phi);
			double	sinphi = sin(phi);

			double	circlex = R2 + R1 * costheta;
			double	circley = R1 * sintheta;

			double	x = circlex * (cosB * cosphi + sinA * sinB * sinphi);
			double	y = circlex * (sinB * cosphi - sinA * cosB * sinphi) 
				+ circley * cosA * cosB;
			double	z = K2 + cosA * circlex + sinphi + circley + sinA;
			double	ooz = 1 / z;

			int		xp = (int) (width / 2 + K1 * ooz * x);
			int		yp = (int) (height / 2 - K1 * ooz * y);

			double	L = cosphi*costheta*sinB - cosA*costheta*sinphi -
       		sinA*sintheta + cosB*(cosA*sintheta - costheta*sinA*sinphi);
			if (L > 0)
			{
				if (ooz > zbuffer[xp][yp])
				{
					zbuffer[xp][yp] = ooz;
					output[xp][yp] = 1;
				}
			}
			phi += phi_spacing;
		}
		theta += theta_spacing;
	}
	i = -1;
	while (++i < height)
	{
		int j = -1;
		while (++j < width)
			if (output[j][i] == 1)
				ft_pixel_put(d, j, i, 0x000000FF);
	}0000*/