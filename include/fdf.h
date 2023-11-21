/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:28:12 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/21 13:07:06 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"


/* Our main data structure
 *	Contains all of the informations about our image
*/
typedef struct	s_fdf {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_fdf;

#endif