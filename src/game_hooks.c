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

static void	set_key_state(t_vars *vars, int keycode, int state)
{
	if (keycode == 119 || keycode == 13)
		vars->key_w = state;
	else if (keycode == 97 || keycode == 0)
		vars->key_a = state;
	else if (keycode == 115 || keycode == 1)
		vars->key_s = state;
	else if (keycode == 100 || keycode == 2)
		vars->key_d = state;
	else if (keycode == 65361 || keycode == 123)
		vars->key_left = state;
	else if (keycode == 65363 || keycode == 124)
		vars->key_right = state;
}

int	key_press_hook(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == 53)
		close_win(game);
	set_key_state(&game->vars, keycode, 1);
	return (0);
}

int	key_release_hook(int keycode, t_game *game)
{
	set_key_state(&game->vars, keycode, 0);
	return (0);
}

static void	apply_movement(t_game *game)
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
	apply_movement(game);
	render_frame(game);
	return (0);
}

void	place_player_and_hook(t_game *game)
{
	if (find_player(&game->map, &game->player))
		return ;
	mlx_hook(game->vars.win, 2, 1L << 0, key_press_hook, game);
	mlx_hook(game->vars.win, 3, 1L << 1, key_release_hook, game);
	mlx_hook(game->vars.win, 17, 0, close_win, game);
	mlx_loop_hook(game->vars.mlx, game_loop, game);
}
