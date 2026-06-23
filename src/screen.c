/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:46:53 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/23 13:11:51 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_screen(t_game *game)
{
	game->screen.img = mlx_new_image(game->vars.mlx, game->vars.win_width,
			game->vars.win_height);
	if (!game->screen.img)
	{
		printf("Error\nFailed to create new screen image\n");
		return (1);
	}
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.bits_per_pixel, &game->screen.line_length,
			&game->screen.endian);
	if (!game->screen.addr)
	{
		printf("Error\nFailed to get data addr\n");
		mlx_destroy_image(game->vars.mlx, game->screen.img);
		game->screen.img = NULL;
		return (1);
	}
	return (0);
}
