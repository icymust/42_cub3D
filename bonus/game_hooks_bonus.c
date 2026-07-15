/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:13:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/12 18:42:22 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

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
	else if (keycode == 32)
		open_door(game);
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
	mlx_hook(game->vars.win, 2, 1L << 0, key_press_hook, game);
	mlx_hook(game->vars.win, 3, 1L << 1, key_release_hook, game);
	mlx_hook(game->vars.win, 17, 0, close_win, game);
	mlx_hook(game->vars.win, 6, 1L << 6, mouse_hook, game);
	mlx_loop_hook(game->vars.mlx, game_loop, game);
	mlx_mouse_hide();
	mlx_mouse_move(game->vars.win, game->vars.win_width / 2,
		game->vars.win_height / 2);
}
