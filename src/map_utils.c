/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:57:27 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/10 18:57:57 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	free_partial_grid(t_map *map, int count)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < count)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
}

static int	finalize_read(t_map *map, int i, int h)
{
	if (i != h)
	{
		free_partial_grid(map, i);
		return (1);
	}
	map->grid[i] = NULL;
	return (0);
}

int	map_name_check(const char *filename)
{
	int	length;

	length = ft_strlen(filename);
	if (length < 4)
		return (1);
	if (ft_strncmp(&filename[length - 4], ".cub", 4) == 0)
		return (0);
	return (1);
}

int	read_grid(t_map *map, const char *filename, int height)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		free_partial_grid(map, 0);
		return (1);
	}
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->grid[i++] = line;
	}
	close(fd);
	return (finalize_read(map, i, height));
}

int	count_lines(const char *filename)
{
	int		fd;
	int		cnt;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	cnt = 0;
	line = get_next_line(fd);
	while (line)
	{
		cnt++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (cnt);
}
