/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:26:11 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/15 16:19:29 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	spawn_check(int spawn)
{
	if (spawn == 0)
	{
		ft_printf("Error\nMap must contain one player\n");
		return (1);
	}
	if (spawn > 1)
	{
		ft_printf("Error\nMap contains multiple players\n");
		return (1);
	}
	return (0);
}

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
			{
				ft_printf("Error\nInvalid map character\n");
				return (1);
			}
		}
	}
	if (spawn_check(m->spawn))
		return (1);
	return (0);
}

int	grid_check(t_map *m)
{
	if (count_elems(m))
		return (1);
	if (check_map_closed(m))
	{
		ft_printf("Error\nMap is not closed\n");
		return (1);
	}
	return (0);
}
