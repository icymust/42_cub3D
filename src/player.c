/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 16:19:09 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/21 20:46:12 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	setup_dir(t_player *player, char dir)
{
	player->dir_x = 0;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0;
	if (dir == 'N')
	{
		player->dir_y = -1;
		player->plane_x = PLANE_LEN;
	}
	else if (dir == 'S')
	{
		player->dir_y = 1;
		player->plane_x = -PLANE_LEN;
	}
	else if (dir == 'E')
	{
		player->dir_x = 1;
		player->plane_y = PLANE_LEN;
	}
	else if (dir == 'W')
	{
		player->dir_x = -1;
		player->plane_y = -PLANE_LEN;
	}
}

int	find_player(t_map *m, t_player *player)
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
				player->pos_y = pos.y + 0.5;
				player->pos_x = pos.x + 0.5;
				setup_dir(player, m->grid[pos.y][pos.x]);
				return (0);
			}
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}
