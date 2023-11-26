/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:13:30 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/26 09:20:24 by nsalles          ###   ########.fr       */
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
