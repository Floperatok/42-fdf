/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:36:49 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/26 10:15:59 by nsalles          ###   ########.fr       */
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

void	free_data(t_fdf *data)
{
	if (data->map)
		free(data->map);
	free(data->mlx);
	free(data);
}

void	error_handler(t_fdf *data)
{
	free_data(data);
	perror("Error");
	exit(EXIT_FAILURE);
}

int	end(t_fdf *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free_data(data);
	exit(EXIT_SUCCESS);
}
