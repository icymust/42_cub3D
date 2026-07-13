/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:14:18 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/13 14:40:48 by mmustone         ###   ########.fr       */
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
	if (g->screen.img)
	{
		mlx_destroy_image(g->vars.mlx, g->screen.img);
		g->screen.img = NULL;
		g->screen.addr = NULL;
	}
}

static void	free_config(t_config *config)
{
	free(config->no);
	free(config->so);
	free(config->we);
	free(config->ea);
	config->no = NULL;
	config->so = NULL;
	config->we = NULL;
	config->ea = NULL;
}

int	close_win(t_game *game)
{
	if (!game)
		exit(0);
	destroy_images(game);
	if (game->vars.mlx && game->vars.win)
	{
		mlx_destroy_window(game->vars.mlx, game->vars.win);
		free(game->vars.mlx);
		game->vars.win = NULL;
	}
	free_map(&game->map);
	free_config(&game->config);
	exit(0);
	return (0);
}

int	game_loop(t_game *game)
{
	apply_movement(game);
	render_frame(game);
	return (0);
}
