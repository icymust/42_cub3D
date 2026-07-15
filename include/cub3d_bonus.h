/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 15:30:33 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/15 15:30:34 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

# define MM_X 10
# define MM_Y 10
# define MM_TILE 16
# define MM_SIZE 160
# define MM_RADIUS 5
# define MM_PLAYER_WIDTH 9
# define MM_PLAYER_HEIGHT 9
# define MM_WALL_COLOR 0x20242A
# define MM_FLOOR_COLOR 0xE8E4DC
# define MM_PLAYER_COLOR 0xE84A2A
# define MM_DOOR_COLOR 0xA0522D

void	draw_minimap(t_game *game);
void	open_door(t_game *game);
void	put_pixel(t_img *img, int x, int y, int color);
void	bonus_mouse_center(t_game *game);
void	bonus_mouse_hide(t_game *game);

#endif
