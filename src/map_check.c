/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:26:11 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 13:58:23 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	count_elems(t_map *m)
{
	int		y;
	int		x;
	char	c;

	m->spawn = 0;
	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (m->grid[y][++x])
		{
			c = m->grid[y][x];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
				m->spawn++;
			else if (c != '0' && c != '1' && c != ' ')
				return (1);
		}
	}
	return (0);
}

int	find_player(t_map *m, int *sy, int *sx)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < m->height)
	{
		pos.x = 0;
		while (m->grid[pos.y][pos.x])
		{
			if (m->grid[pos.y][pos.x] == 'N' || m->grid[pos.y][pos.x] == 'S'
				|| m->grid[pos.y][pos.x] == 'E' || m->grid[pos.y][pos.x] == 'W')
			{
				*sy = pos.y;
				*sx = pos.x;
				return (0);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}

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

static int	check_map_closed(t_map *m)
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

int	grid_check(t_map *m)
{
	if (count_elems(m))
		return (1);
	if (m->spawn != 1)
		return (1);
	if (check_map_closed(m))
		return (1);
	return (0);
}
