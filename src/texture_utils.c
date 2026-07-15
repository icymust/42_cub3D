/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 14:26:04 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/13 14:27:21 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

t_tex_id	choose_tex_id(t_ray *ray)
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
