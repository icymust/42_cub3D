/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:00:00 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/15 16:00:00 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

static void	apply_bonus_movement(t_game *game)
{
	if (game->vars.key_w)
		move_player(game, MV_SP, 0);
	if (game->vars.key_s)
		move_player(game, -MV_SP, 0);
	if (game->vars.key_a)
		move_player(game, -MV_SP, 1);
	if (game->vars.key_d)
		move_player(game, MV_SP, 1);
	if (game->vars.key_left)
		rotate_player(game, -ROT_SP);
	if (game->vars.key_right)
		rotate_player(game, ROT_SP);
}

int	game_loop(t_game *game)
{
	apply_bonus_movement(game);
	render_frame(game);
	return (0);
}
