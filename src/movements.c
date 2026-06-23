/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:12:25 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/23 13:12:27 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	can_move_to(t_game *game, double x, double y)
{
	if (game->map.grid[(int)y][(int)(x + COL_BUF)] == '1')
		return (0);
	if (game->map.grid[(int)y][(int)(x - COL_BUF)] == '1')
		return (0);
	if (game->map.grid[(int)(y + COL_BUF)][(int)x] == '1')
		return (0);
	if (game->map.grid[(int)(y - COL_BUF)][(int)x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, double move, int strafe)
{
	double	move_x;
	double	move_y;
	double	new_x;
	double	new_y;

	if (strafe)
	{
		move_x = -game->player.dir_y;
		move_y = game->player.dir_x;
	}
	else
	{
		move_x = game->player.dir_x;
		move_y = game->player.dir_y;
	}
	new_x = game->player.pos_x + move_x * move;
	new_y = game->player.pos_y + move_y * move;
	if (can_move_to(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (can_move_to(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	old_dir_x = game->player.dir_x;
	old_dir_y = game->player.dir_y;
	old_plane_x = game->player.plane_x;
	old_plane_y = game->player.plane_y;
	game->player.dir_x = old_dir_x * cos(angle) - old_dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + old_dir_y * cos(angle);
	game->player.plane_x = old_plane_x * cos(angle) - old_plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + old_plane_y * cos(angle);
}
