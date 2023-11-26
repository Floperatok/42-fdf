/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:28:12 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/26 10:53:27 by nsalles          ###   ########.fr       */
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
# define BLACK 0x00000000

typedef struct	s_point
{
	double	x;
	double	y;
	double	z;
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

	t_point	*map;
	int		map_ysize;
	int		map_xsize;

	t_point	origin;
	int		scale;
}				t_fdf;

t_fdf	*ft_init(void);

void	assign_point(t_point *point, int x, int y, int z);

void	create_map(t_fdf *data, char *file);

void	ft_pixel_put(t_fdf *data, int x, int y, int color);
void	fill_black(t_fdf *data);
void	draw_line(t_fdf *data, t_point *a, t_point *b);
void	draw_donut(t_fdf *data, double A_tmp, double B_tmp);

void	render(t_fdf *data);

void	free_tab(char **tab);
void	error_handler(t_fdf *data);
int		end(t_fdf *data);

#endif