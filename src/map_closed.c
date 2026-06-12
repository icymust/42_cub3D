/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_closed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:38:03 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 18:40:09 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static int	is_walkable(char c)
{
	return (c == '0' || is_player(c));
}

static int	is_outside_map(t_map *m, int y, int x)
{
	if (y < 0 || y >= m->height)
		return (1);
	if (x < 0 || x >= (int)ft_strlen(m->grid[y]))
		return (1);
	return (0);
}

static int	check_cell_closed(t_map *m, int y, int x)
{
	if (is_outside_map(m, y - 1, x) || m->grid[y - 1][x] == ' ')
		return (1);
	if (is_outside_map(m, y + 1, x) || m->grid[y + 1][x] == ' ')
		return (1);
	if (is_outside_map(m, y, x - 1) || m->grid[y][x - 1] == ' ')
		return (1);
	if (is_outside_map(m, y, x + 1) || m->grid[y][x + 1] == ' ')
		return (1);
	return (0);
}

int	check_map_closed(t_map *m)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < m->height)
	{
		pos.x = 0;
		while (m->grid[pos.y][pos.x])
		{
			if (is_walkable(m->grid[pos.y][pos.x]))
			{
				if (check_cell_closed(m, pos.y, pos.x))
					return (1);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (0);
}
