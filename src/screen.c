/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 12:46:53 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/16 12:47:06 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	init_screen(t_game *game)
{
	game->screen.img = mlx_new_image(game->vars.mlx,
			game->vars.win_width, game->vars.win_height);
	if (!game->screen.img)
		return (1);
	game->screen.addr = mlx_get_data_addr(game->screen.img,
			&game->screen.bits_per_pixel,
			&game->screen.line_length,
			&game->screen.endian);
	if (!game->screen.addr)
		return (1);
	return (0);
}
