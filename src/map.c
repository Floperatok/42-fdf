/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:41:46 by nsalles           #+#    #+#             */
/*   Updated: 2024/02/12 22:48:32 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 *	Find the dimension x of the map, returns -1 if the file of the map is not
 *		found or the file is empty.
*/
static int	get_size_x(char *file)
{
	int		counter;
	int		i;
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	close(fd);
	if (line == NULL)
		return (-1);
	counter = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' && line[i])
			i++;
		if (line[i])
			counter++;
		while (line[i] != ' ' && line[i])
			i++;
	}
	free(line);
	return (counter);
}

/*
 *	Find the dimension y of the map, returns -1 if the file of the map
 *		is not found.
*/
static int	get_size_y(char *file)
{
	int		counter;
	int		fd;
	char	buf;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
		return (-1);
	counter = 0;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			counter++;
	}
	close(fd);
	return (counter);
}

/*
 *	Read the file, split each row and return all of the file content 
 *		in the null terminated char***.
 *	In case of an error, returns NULL.
*/
static char	***read_map(char *file, int size_y)
{
	int		fd;
	char	*line;
	char	***char_map;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	char_map = malloc(sizeof(char **) * (size_y + 1));
	if (!char_map)
	{
		close(fd);
		return (NULL);
	}
	i = 0;
	while (i < size_y)
	{
		line = get_next_line(fd);
		char_map[i++] = ft_split(line, ' ');
		free(line);
	}
	get_next_line(-1);
	close(fd);
	char_map[i] = NULL;
	return (char_map);
}

/*
 *	Fill up the data structure with the dimensions of the map.
*/
static void	get_file_dimensions(t_fdf *d, char *file)
{
	d->map_xsize = get_size_x(file);
	d->map_ysize = get_size_y(file);
	if (d->map_xsize == -1 || d->map_ysize == -1)
		error_handler(d);
}

/*
 *	Fill the data->map with all the points find in the map.
 *	data->map is null terminated.
 *	Also assign to data->map_xsize and data->map_ysize the dimensions of the map
*/
void	create_map(t_fdf *d, char *file)
{
	char	***char_map;
	int		x;
	int		y;

	get_file_dimensions(d, file);
	d->map = malloc(sizeof(t_point) * (d->map_xsize * d->map_ysize + 1));
	if (!d->map)
		error_handler(d);
	char_map = read_map(file, d->map_ysize);
	if (!char_map)
		error_handler(d);
	y = -1;
	while (++y < d->map_ysize)
	{
		x = -1;
		while (++x < d->map_xsize)
		{
			assign_point(&(d->map[d->map_xsize * y + x]), x, y, \
						ft_atoi(char_map[y][x]));
			d->map[d->map_xsize * y + x].color = get_color(char_map[y][x]);
		}
	}
	free_char_map(char_map);
}
