/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:14:39 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/08 13:21:32 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d_bonus.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	draw_floor_ceiling(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->vars.win_height)
	{
		x = 0;
		while (x < game->vars.win_width)
		{
			if (y < game->vars.win_height / 2)
				put_pixel(&game->screen, x, y, game->config.ceiling_color);
			else
				put_pixel(&game->screen, x, y, game->config.floor_color);
			x++;
		}
		y++;
	}
}

static int	get_wall_color(t_ray *ray)
{
	if (ray->side == 0)
		return (0x00DDDDDD);
	return (0x00888888);
}

static void	draw_wall_slice(t_game *game, int x, t_wall *wall, t_ray *ray)
{
	int	y;
	int	color;

	y = wall->draw_start;
	color = get_wall_color(ray);
	while (y <= wall->draw_end)
	{
		put_pixel(&game->screen, x, y, color);
		y++;
	}
}

int	render_frame(t_game *game)
{
	int		x;
	t_ray	ray;
	t_wall	wall;

	draw_floor_ceiling(game);
	x = 0;
	while (x < game->vars.win_width)
	{
		init_ray(game, &ray, x);
		init_ray_steps(game, &ray);
		perform_dda(game, &ray);
		calc_wall_distance(&ray);
		calc_wall_slice(game, &ray, &wall);
		draw_wall_slice(game, x, &wall, &ray);
		x++;
	}
	draw_minimap(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->screen.img, 0,
		0);
	return (0);
}
