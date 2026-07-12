/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 15:14:39 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/24 20:36:48 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

static int	get_texture_pixel(t_texture *tex, int tex_x, int tex_y)
{
	char	*pixel;

	pixel = tex->addr + (tex_y * tex->line_length
			+ tex_x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

static void	draw_wall_slice(t_game *game, int x, t_wall *wall, t_ray *ray)
{
	t_texture	*tex;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			y;

	tex = select_texture(game, ray);
	tex_x = calc_tex_x(tex, ray);
	step = (double)tex->height / wall->line_height;
	tex_pos = (wall->draw_start - game->vars.win_height / 2.0
			+ wall->line_height / 2.0) * step;
	y = wall->draw_start;
	while (y <= wall->draw_end)
	{
		put_pixel(&game->screen, x, y,
			get_texture_pixel(tex, tex_x, (int)tex_pos % tex->height));
		tex_pos += step;
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
		calc_wall_x(game, &ray);
		calc_wall_slice(game, &ray, &wall);
		draw_wall_slice(game, x, &wall, &ray);
		x++;
	}
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->screen.img, 0,
		0);
	return (0);
}
