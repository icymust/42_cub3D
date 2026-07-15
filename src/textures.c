/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/15 14:52:05 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/13 14:27:45 by mmustone         ###   ########.fr       */
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
