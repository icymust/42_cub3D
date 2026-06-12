/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:13:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 13:53:45 by mmustone         ###   ########.fr       */
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
	if (keycode == 65307)
	{
		print_key_hook("ESC\n");
		close_win(game);
	}
	else if (keycode == 119)
		print_key_hook("W\n");
	else if (keycode == 97)
		print_key_hook("A\n");
	else if (keycode == 115)
		print_key_hook("S\n");
	else if (keycode == 100)
		print_key_hook("D\n");
	else if (keycode == 65361)
		print_key_hook("<-\n");
	else if (keycode == 65363)
		print_key_hook("->\n");
	return (0);
}

void	hook(t_game *game)
{
	mlx_hook(game->vars.win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->vars.win, 17, 0, close_win, game);
}