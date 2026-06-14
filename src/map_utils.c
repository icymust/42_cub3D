/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:57:27 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/14 20:02:20 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_partial_grid(t_map *map, int count)
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

int	finalize_read(t_map *map, int i, int h)
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
	if (length < 5)
	{
		printf("Error\nInvalid filename\n");
		return (1);
	}
	if (ft_strncmp(&filename[length - 4], ".cub", 4) == 0)
		return (0);
	printf("Error\nMap file must have .cub extension\n");
	return (1);
}
