/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:53:31 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 13:03:06 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map || !map->grid)
		return ;
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i])
			free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
	map->height = 0;
	map->width = 0;
}

static int	validate_dimensions(t_map *map)
{
	if (map->height < 3)
	{
		ft_printf("Error\nMap is too small\n");
		return (1);
	}
	return (0);
}

static int	alloc_and_read(t_map *map, const char *filename)
{
	int	height;

	height = count_lines(filename);
	if (height < 0)
	{
		ft_printf("Error\nCannot open map file\n");
		return (1);
	}
	if (height < 3)
	{
		ft_printf("Error\nMap is too small\n");
		return (1);
	}
	map->grid = malloc(sizeof(char *) * (height + 1));
	if (!map->grid)
	{
		ft_printf("Error\nMalloc\n");
		return (1);
	}
	if (read_grid(map, filename, height))
	{
		ft_printf("Error\nMap problem\n");
		return (1);
	}
	map->height = height;
	map->width = ft_strlen(map->grid[0]);
	return (0);
}

int	map_load(t_map *map, char *filename)
{
	if (!map || !filename)
		return (1);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
	if (map_name_check(filename))
		return (1);
	if (alloc_and_read(map, filename))
		return (1);
	if (validate_dimensions(map))
	{
		free_map(map);
		return (1);
	}
	if (grid_check(map))
	{
		ft_printf("Error\nMap validation error\n");
		free_map(map);
		return (1);
	}
	return (0);
}
