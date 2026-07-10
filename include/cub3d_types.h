/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 13:25:17 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/23 13:26:49 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_TYPES_H
# define CUB3D_TYPES_H

typedef enum e_tex_id
{
	TEX_NO,
	TEX_SO,
	TEX_WE,
	TEX_EA
}				t_tex_id;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	int			key_w;
	int			key_a;
	int			key_s;
	int			key_d;
	int			key_left;
	int			key_right;
}				t_vars;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	int			steps;
}				t_player;

typedef struct s_config
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			floor_color;
	int			ceiling_color;
	int			has_floor;
	int			has_ceiling;
}				t_config;

typedef struct s_texture
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_texture;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_wall
{
	int			line_height;
	int			draw_start;
	int			draw_end;
}				t_wall;

typedef struct s_ray
{
	double		camera_x;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		wall_x;
}				t_ray;

typedef struct s_map
{
	char		**grid;
	int			width;
	int			height;
	int			spawn;
}				t_map;

typedef struct s_game
{
	t_vars		vars;
	t_map		map;
	t_player	player;
	t_config	config;
	t_texture	textures[4];
	t_img		screen;
}				t_game;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

#endif