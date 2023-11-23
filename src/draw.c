/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:44:00 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/23 16:49:49 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	Write on the image a pixel of the color of your choice
 *	on the given coordinates
*/
void	ft_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	fill_black(t_fdf *data, int width, int height)
{
	int	i;
	int	j;

	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			ft_pixel_put(data, j, i, 0x000000);
	}
}

void	draw_donut(t_fdf *data, double A_tmp, double B_tmp)
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
				ft_pixel_put(data, j, i, 0x00FFFFFF);
	}
}
