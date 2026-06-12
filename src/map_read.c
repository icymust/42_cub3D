/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:34:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 18:35:51 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	store_map_line(t_map *map, char *line, int *i)
{
	if (line[0] && line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	map->grid[*i] = line;
	(*i)++;
	return (0);
}

static int	open_map_file(t_map *map, const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_partial_grid(map, 0);
		return (-1);
	}
	return (fd);
}

int	read_grid(t_map *map, const char *filename, int height)
{
	int		fd;
	int		i;
	int		in_map;
	char	*line;

	fd = open_map_file(map, filename);
	if (fd < 0)
		return (1);
	i = 0;
	in_map = 0;
	line = get_next_line(fd);
	while (line && i < height)
	{
		if (!in_map && is_map_line(line))
			in_map = 1;
		if (in_map)
			store_map_line(map, line, &i);
		else
			free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (finalize_read(map, i, height));
}

int	count_map_lines(const char *filename)
{
	int		fd;
	int		cnt;
	int		in_map;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	cnt = 0;
	in_map = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (!in_map && is_map_line(line))
			in_map = 1;
		if (in_map)
			cnt++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (cnt);
}
