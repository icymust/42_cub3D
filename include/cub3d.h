/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:44:28 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/21 22:50:05 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MV_SP 0.1
# define PLANE_LEN 0.66
# define COL_BUF 0.2

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

void			place_player_and_hook(t_game *game);
int				close_win(t_game *game);
int				count_map_lines(const char *filename);
int				read_grid(t_map *map, const char *filename, int height);
int				map_name_check(const char *filename);
int				map_load(t_map *map, char *filename);
void			free_map(t_map *map);
int				grid_check(t_map *m);
int				find_player(t_map *m, t_player *player);
int				config_parse(t_config *config, char *filename);
void			free_split(char **rgb);
int				is_config_line(char *line);
int				is_map_line(char *line);
int				is_empty_line(char *line);
int				config_save(t_config *config, char *line);
int				parse_color(int *dst, int *has_color, char *color);
int				handle_parse_status(int fd, int status);
int				finalize_read(t_map *map, int i, int h);
void			free_partial_grid(t_map *map, int count);
int				check_map_closed(t_map *m);
void			drain_file(int fd);
char			**split_rgb(char *color);
int				load_textures(t_game *game);
void			destroy_images(t_game *g);
int				init_screen(t_game *game);
int				render_frame(t_game *game);
void			init_ray(t_game *game, t_ray *ray, int x);
void			init_ray_steps(t_game *game, t_ray *ray);
void			perform_dda(t_game *game, t_ray *ray);
void			calc_wall_distance(t_ray *ray);
void			calc_wall_slice(t_game *game, t_ray *ray, t_wall *wall);
void			move_player(t_game *game, double move, int strafe);

#endif
