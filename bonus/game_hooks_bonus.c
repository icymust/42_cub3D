/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:13:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/01 16:30:29 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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

int	mouse_hook(int x, int y, t_game *game)
{
	int	center_x;
	int	delta_x;

	(void)y;
	center_x = game->vars.win_width / 2;
	if (x == center_x)
		return (0);
	delta_x = x - center_x;
	rotate_player(game, delta_x * 0.003);
	mlx_mouse_move(game->vars.win, center_x, game->vars.win_height / 2);
	render_frame(game);
	return (0);
}

void	place_player_and_hook(t_game *game)
{
	if (find_player(&game->map, &game->player))
		return ;
	mlx_hook(game->vars.win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->vars.win, 17, 0, close_win, game);
	mlx_hook(game->vars.win, 6, 1L << 6, mouse_hook, game);
	mlx_mouse_hide();
	mlx_mouse_move(game->vars.win, game->vars.win_width / 2,
		game->vars.win_height / 2);
}
