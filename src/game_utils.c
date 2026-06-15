/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:14:18 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/15 15:09:15 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_split(char **rgb)
{
	int	i;

	if (!rgb)
		return ;
	i = 0;
	while (rgb[i])
	{
		free(rgb[i]);
		i++;
	}
	free(rgb);
}

void	destroy_images(t_game *g)
{
	int	i;

	if (!g || !g->vars.mlx)
		return ;
	i = 0;
	while (i < 4)
	{
		if (g->textures[i].img)
		{
			mlx_destroy_image(g->vars.mlx, g->textures[i].img);
			g->textures[i].img = NULL;
		}
		i++;
	}
}

int	close_win(t_game *game)
{
	if (!game)
		exit(0);
	destroy_images(game);
	if (game->vars.mlx && game->vars.win)
	{
		mlx_destroy_window(game->vars.mlx, game->vars.win);
		game->vars.win = NULL;
	}
	exit(0);
	return (0);
}
