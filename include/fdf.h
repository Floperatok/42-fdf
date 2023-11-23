/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:28:12 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/23 16:54:56 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/libft.h"
# include "../libs/ft_printf/include/ft_printf.h"
# include "../libs/minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define SCREEN_H 1080
# define SCREEN_W 1920

# define WHITE 0x00FFFFFF

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}				t_point;


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

	char 	***map;
	double	A;
}				t_fdf;

t_fdf	*ft_init(void);

void	read_map(t_fdf *data, char *file);

void	ft_pixel_put(t_fdf *data, int x, int y, int color);
void	fill_black(t_fdf *data, int width, int height);
void	draw_player(t_fdf *data, int size);
void	draw_donut(t_fdf *data, double A_tmp, double B_tmp);

void	error_handler(t_fdf *data);
int		end(t_fdf *data);

#endif