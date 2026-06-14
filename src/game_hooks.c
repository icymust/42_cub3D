/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:13:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/14 18:12:11 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	print_key_hook(char *s)
{
	printf("%s", s);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307 || keycode == 53)
	{
		print_key_hook("ESC\n");
		close_win(game);
	}
	else if (keycode == 119 || keycode == 13)
		print_key_hook("W\n");
	else if (keycode == 97 || keycode == 0)
		print_key_hook("A\n");
	else if (keycode == 115 || keycode == 1)
		print_key_hook("S\n");
	else if (keycode == 100 || keycode == 2)
		print_key_hook("D\n");
	else if (keycode == 65361 || keycode == 123)
		print_key_hook("<-\n");
	else if (keycode == 65363 || keycode == 124)
		print_key_hook("->\n");
	return (0);
}

void	hook(t_game *game)
{
	mlx_hook(game->vars.win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->vars.win, 17, 0, close_win, game);
}
