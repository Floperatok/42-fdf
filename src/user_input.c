/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:45:32 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 22:55:10 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	user_input4(int keycode, t_fdf *d)
{
	if (keycode == 112)
	{
		if (d->plan == 1)
			d->plan = 0;
		else
			d->plan = 1;
	}
	else if (keycode == 65289)
	{
		if (d->auto_rotation == 0)
			d->auto_rotation = 1;
		else
			d->auto_rotation = 0;
	}
	else if (keycode == 65451 && d->scale < 100)
	{
		d->scale += 1;
		d->origin.x -= d->map_xsize / 2;
		d->origin.y -= d->map_ysize / 2;
	}
}

static void	user_input3(int keycode, t_fdf *d)
{
	if (keycode == 32)
	{
		if (d->projection)
		{
			d->rotx = 0;
			d->roty = 0;
			d->rotz = 0;
			d->projection = 0;
		}
		else
		{
			d->rotx = 0.50;
			d->roty = -0.25;
			d->rotz = 0.25;
			d->depth = 0.15;
			d->projection = 1;
		}
	}
	else
		user_input4(keycode, d);
}

static void	user_input2(int keycode, t_fdf *d)
{
	if (keycode == 114 && d->line_thickness > 1)
		d->line_thickness--;
	else if (keycode == 116 && d->line_thickness < 10)
		d->line_thickness++;
	else if (keycode == 65450 && d->depth < 8)
		d->depth *= 1.2;
	else if (keycode == 65455)
		d->depth /= 1.2;
	else if (keycode == 97)
		d->roty += -ROTATION_SPEED;
	else if (keycode == 100)
		d->roty += ROTATION_SPEED;
	else if (keycode == 115)
		d->rotx += -ROTATION_SPEED;
	else if (keycode == 119)
		d->rotx += ROTATION_SPEED;
	else if (keycode == 113)
		d->rotz += ROTATION_SPEED;
	else if (keycode == 101)
		d->rotz += -ROTATION_SPEED;
	else
		user_input3(keycode, d);
}

/*
 *	Listing of all the user inputs.
*/
int	user_input(int keycode, t_fdf *d)
{
	if (keycode == 65307)
		end(d);
	else if (keycode == 65362)
		d->origin.y -= 20;
	else if (keycode == 65363)
		d->origin.x += 20;
	else if (keycode == 65364)
		d->origin.y += 20;
	else if (keycode == 65361)
		d->origin.x -= 20;
	else if (keycode == 65453 && d->scale > 2)
	{
		d->scale -= 1;
		d->origin.x += d->map_xsize / 2;
		d->origin.y += d->map_ysize / 2;
	}
	else
		user_input2(keycode, d);
	apply_change(d);
	render(d);
	return (0);
}
