/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:05:33 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/28 15:22:56 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	Assign coordonates values to the given address of point structure
*/
void	assign_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

void	apply_offset(t_point offset, t_point *point)
{
	point->x = point->x + offset.x;
	point->y = point->y + offset.y;
}

void	apply_scale(double scale, t_point *point, int plan)
{
	if (plan == 0)
	{
		point->x = point->x * (scale * point->z / 5);
		point->y = point->y * (scale * point->z / 5);
		point->z = point->z * (scale * point->z / 5);
	}
	else
	{
		point->x = point->x * scale;
		point->y = point->y * scale;
		point->z = point->z * scale;
	}
}

void	apply_depth(double depth, t_point *point)
{
	point->z = point->z * depth;
}

void	apply_change(t_fdf *d)
{
	int	y;
	int	x;
	int	i;

	y = -1;
	while (++y < d->map_ysize)
	{
		x = -1;
		while (++x < d->map_xsize)
		{
			i = y * d->map_xsize + x;
			d->map_end[i].color = d->map[i].color;
			assign_point(&(d->map_end[i]), d->map[i].x, d->map[i].y, \
														d->map[i].z);
			apply_depth(d->depth, &(d->map_end[i]));
			rot_x_point(&(d->map_end[i]), d->rotx, d->map_ysize);
			rot_y_point(&(d->map_end[i]), d->roty, d->map_xsize);
			rot_z_point(&(d->map_end[i]), d->rotz);
			apply_scale(d->scale, &(d->map_end[i]), d->plan);
			apply_offset(d->origin, &(d->map_end[i]));
		}
	}
}
