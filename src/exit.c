/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:36:49 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 22:45:13 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	Free the array of strings.
*/
void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

/*
 *	Free all the data structure.
*/
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
*/
void	free_char_map(char ***char_map)
{
	int	i;

	i = -1;
	while (char_map[++i])
		free_array(char_map[i]);
	free(char_map);
}

/*
 *	Free all the data structure and exit with an error.
*/
void	error_handler(t_fdf *d)
{
	free_data(d);
	perror("Error");
	exit(EXIT_FAILURE);
}

/*
 *	Closing program function, free everything and close the window.
*/
int	end(t_fdf *d)
{
	mlx_destroy_image(d->mlx, d->img);
	mlx_destroy_window(d->mlx, d->window);
	mlx_destroy_display(d->mlx);
	free_data(d);
	exit(EXIT_SUCCESS);
}
