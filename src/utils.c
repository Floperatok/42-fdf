/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 09:13:30 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 22:56:06 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	test_base(char *base)
{
	int	i;
	int	j;
	int	len_base;

	len_base = ft_strlen(base);
	if (len_base < 2)
		return (1);
	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+' || base[i] < 32 || base[i] > 126)
			return (1);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	get_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c)
		i++;
	return (i);
}

/*
 *	Convert the given string into integer in the given base.
*/
int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	i;
	int	result;
	int	len_base;

	sign = 1;
	i = 0;
	result = 0;
	len_base = ft_strlen(base);
	if (test_base(base))
		return (0);
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (is_in_base(str[i], base) && str[i])
	{
		result = result * len_base + get_base_index(str[i], base);
		i++;
	}
	return (result * sign);
}
