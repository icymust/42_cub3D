/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:52:05 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/23 13:20:18 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	load_one_texture(void *mlx, t_texture *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		return (1);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
	if (!tex->addr)
		return (1);
	return (0);
}

static int	texture_error(void)
{
	printf("Error\nFailed to load textures\n");
	return (1);
}

static t_tex_id	choose_tex_id(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_x > 0)
			return (TEX_WE);
		return (TEX_EA);
	}
	if (ray->dir_y > 0)
		return (TEX_NO);
	return (TEX_SO);
}

t_texture	*select_texture(t_game *game, t_ray *ray)
{
	return (&game->textures[choose_tex_id(ray)]);
}

int	calc_tex_x(t_texture *tex, t_ray *ray)
{
	int	tex_x;

	tex_x = (int)(ray->wall_x * tex->width);
	if (ray->side == 0 && ray->dir_x > 0)
		tex_x = tex->width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

int	load_textures(t_game *game)
{
	if (load_one_texture(game->vars.mlx, &game->textures[TEX_NO],
			game->config.no))
		return (texture_error());
	if (load_one_texture(game->vars.mlx, &game->textures[TEX_SO],
			game->config.so))
		return (texture_error());
	if (load_one_texture(game->vars.mlx, &game->textures[TEX_WE],
			game->config.we))
		return (texture_error());
	if (load_one_texture(game->vars.mlx, &game->textures[TEX_EA],
			game->config.ea))
		return (texture_error());
	return (0);
}
