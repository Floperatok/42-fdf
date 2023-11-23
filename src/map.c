/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsalles <nsalles@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:41:46 by nsalles           #+#    #+#             */
/*   Updated: 2023/11/22 01:29:53 by nsalles          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	number_of_line(char *file)
{
	int		counter;
	int		fd;
	char	buf;

	fd = open(file, O_RDONLY, 0777);
	if (fd == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
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
 *	Read the file and split it into data.map
*/
void	read_map(t_fdf *data, char *file)
{
	int		fd;
	int		file_size;
	int		i;
	char	*line;

	file_size = number_of_line(file);
	data->map = (char ***)malloc(sizeof(char **) * (file_size + 1));
	if (!data->map)
		error_handler(data);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_handler(data);
	i = -1;
	while (++i < file_size)
	{
		line = get_next_line(fd);
		data->map[i] = ft_split(line, ' ');
		free(line);
		if (!data->map[i])
			error_handler(data);
	}
	data->map[i] = NULL;
	get_next_line(-1);
	close(fd);
}
