/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:36:49 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/28 16:12:47 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_data(t_fdf *d)
{
	if (d->map)
		free(d->map);
	if (d->map_end)
		free(d->map_end);
	free(d->mlx);
	free(d);
}

/*
 *	Free the char*** map.
 *	Arguments:
 *		char***char_map	: The map.
*/
void	free_char_map(char ***char_map)
{
	int	i;

	i = -1;
	while (char_map[++i])
		free_tab(char_map[i]);
	free(char_map);
}

void	error_handler(t_fdf *d)
{
	free_data(d);
	perror("Error");
	exit(EXIT_FAILURE);
}

int	end(t_fdf *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->window);
	mlx_destroy_display(d->mlx);
	free_data(d);
	exit(EXIT_SUCCESS);
}
