/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:00:00 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/15 16:00:00 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

#ifdef __APPLE__

void	bonus_mouse_center(t_game *game)
{
	mlx_mouse_move(game->vars.win, game->vars.win_width / 2,
		game->vars.win_height / 2);
}

void	bonus_mouse_hide(t_game *game)
{
	(void)game;
	mlx_mouse_hide();
}

#else

void	bonus_mouse_center(t_game *game)
{
	mlx_mouse_move(game->vars.mlx, game->vars.win,
		game->vars.win_width / 2, game->vars.win_height / 2);
}

void	bonus_mouse_hide(t_game *game)
{
	mlx_mouse_hide(game->vars.mlx, game->vars.win);
}

#endif
