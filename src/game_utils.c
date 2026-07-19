/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 17:14:18 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/19 18:49:25 by martinmust       ###   ########.fr       */
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

void	free_config(t_config *config)
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

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	destroy_images(game);
	if (game->vars.mlx)
	{
		if (game->vars.win)
		{
			mlx_destroy_window(game->vars.mlx, game->vars.win);
			game->vars.win = NULL;
		}
		mlx_destroy_display(game->vars.mlx);
		free(game->vars.mlx);
		game->vars.mlx = NULL;
	}
	free_map(&game->map);
	free_config(&game->config);
}

int	close_win(t_game *game)
{
	cleanup_game(game);
	exit(0);
	return (0);
}
