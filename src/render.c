/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:14:39 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/17 12:49:51 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void put_pixel(t_img *img, int x, int y, int color)
{
    char *dst;
    dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

static void fill_screen(t_game *game, int color)
{
    int x;
    int y;

    y = 0;
    while(y < game->vars.win_height)
    {
        x = 0;
        while(x < game->vars.win_width)
        {
            put_pixel(&game->screen, x, y, color);
            x++;
        }
        y++;
    }
}

int	render_frame(t_game *game)
{
	fill_screen(game, game->config.floor_color);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win,
		game->screen.img, 0, 0);
	return (0);
}
