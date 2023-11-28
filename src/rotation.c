/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:27:23 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/28 11:42:36 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_z_point(t_point *point, double rot)
{
	double	x;
	double	y;

	x = (point->x * cos(rot)) - (point->y * sin(rot));
	y = (point->x * sin(rot)) + (point->y * cos(rot));
	point->x = x;
	point->y = y;
}

void	rot_y_point(t_point *point, double rot, int sizex)
{
	double	x;
	double	z;
	double	center_x;

	center_x = point->x - sizex / 2;
	x = (point->z * sin(rot)) + (center_x * cos(rot));
	z = (point->z * cos(rot)) - (point->x * sin(rot));
	point->x = x;
	point->z = z;
}

void	rot_x_point(t_point *point, double rot, int sizey)
{
	double	y;
	double	z;
	double	center_y;

	center_y = point->y - sizey / 2;
	y = (center_y * cos(rot)) - (point->z * sin(rot));
	z = (point->y * sin(rot)) + (point->z * cos(rot));
	point->y = y;
	point->z = z;
}
