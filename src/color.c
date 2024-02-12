/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:36:27 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 22:08:25 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	Convert the color code from string to int.
*/
int	get_color(char *str)
{
	char			*char_color;
	int				pos;
	unsigned int	res;

	if (!ft_strchr(str, ','))
		return (0x00FFFFFF);
	pos = 0;
	while (str[pos] != ',')
		pos++;
	pos += 3;
	char_color = ft_substr(str, pos, ft_strlen(str) - pos);
	res = ft_atoi_base(char_color, "0123456789ABCDEF");
	free(char_color);
	return (res);
}

/*
 *	Returns the color according to the position on the gradient.
*/
int	compute_color(int start_color, int end_color, int pos, int size)
{
	int	r;
	int	g;
	int	b;

	r = (1 - (double)pos / size) * ((start_color >> 16) & 0xFF) + \
		(double)pos / size * ((end_color >> 16) & 0xFF);
	g = (1 - (double)pos / size) * ((start_color >> 8) & 0xFF) + \
		(double)pos / size * ((end_color >> 8) & 0xFF);
	b = (1 - (double)pos / size) * (start_color & 0xFF) + \
		(double)pos / size * (end_color & 0xFF);
	return ((r << 16) | (g << 8) | b);
}
