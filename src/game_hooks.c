/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:13:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/22 00:01:55 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == 53)
		close_win(game);
	else if (keycode == 119 || keycode == 13)
		move_player(game, MV_SP, 0);
	else if (keycode == 97 || keycode == 0)
		move_player(game, -MV_SP, 1);
	else if (keycode == 115 || keycode == 1)
		move_player(game, -MV_SP, 0);
	else if (keycode == 100 || keycode == 2)
		move_player(game, MV_SP, 1);
	else if (keycode == 65361 || keycode == 123)
		rotate_player(game, -ROT_SP);
	else if (keycode == 65363 || keycode == 124)
		rotate_player(game, ROT_SP);
	render_frame(game);
	return (0);
}

void	place_player_and_hook(t_game *game)
{
	if (find_player(&game->map, &game->player))
		return ;
	mlx_hook(game->vars.win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->vars.win, 17, 0, close_win, game);
}
