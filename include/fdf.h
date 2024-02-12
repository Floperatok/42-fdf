/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:28:12 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 23:47:08 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libs/libft/includes/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define SCREEN_H 1080
# define SCREEN_W 1920

# define WHITE	0x00FFFFFF
# define BLACK	0x00000000
# define RED	0x00FF0000

# define ROTATION_SPEED 0.05
# define DEPTH_OF_FIELD 1.5

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}				t_point;

typedef struct s_fdf {
	void	*mlx;
	void	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_point	*map;
	t_point	*map_end;
	int		map_ysize;
	int		map_xsize;
	t_point	origin;
	int		scale;
	int		line_thickness;
	double	depth;
	double	rotx;
	double	roty;
	double	rotz;
	int		do_rot;
	int		projection;
	int		plan;
	int		auto_rotation;
}				t_fdf;

t_fdf	*ft_init(char **av);

void	assign_point(t_point *point, int x, int y, int z);

int		user_input(int keycode, t_fdf *d);

int		get_color(char *value);
int		compute_color(int start_color, int end_color, int pos, int size);
void	create_map(t_fdf *data, char *file);

void	ft_pixel_put(t_fdf *data, t_point p);
void	fill_black(t_fdf *data);
void	draw_line(t_fdf *data, t_point a, t_point b);

void	rot_x_point(t_point *point, double rot, int sizey);
void	rot_y_point(t_point *point, double rot, int sizex);
void	rot_z_point(t_point *point, double rot);

void	apply_change(t_fdf *d);
void	render(t_fdf *d);

int		ft_atoi_base(char *str, char *base);
void	free_array(char **array);
void	free_char_map(char ***char_map);
void	error_handler(t_fdf *data);
int		end(t_fdf *data);

#endif