/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:44:28 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/19 18:49:58 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "cub3d_types.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MV_SP 0.01
# define PLANE_LEN 0.66
# define COL_BUF 0.2
# define ROT_SP 0.009

void		place_player_and_hook(t_game *game);
int			close_win(t_game *game);
int			count_map_lines(const char *filename);
int			read_grid(t_map *map, const char *filename, int height);
int			map_name_check(const char *filename);
int			map_load(t_map *map, char *filename);
void		free_map(t_map *map);
int			grid_check(t_map *m);
int			find_player(t_map *m, t_player *player);
int			config_parse(t_config *config, char *filename);
void		free_split(char **rgb);
int			is_config_line(char *line);
int			is_map_line(char *line);
int			is_empty_line(char *line);
int			config_save(t_config *config, char *line);
int			parse_color(int *dst, int *has_color, char *color);
int			handle_parse_status(int fd, int status);
int			finalize_read(t_map *map, int i, int h);
void		free_partial_grid(t_map *map, int count);
int			check_map_closed(t_map *m);
void		drain_file(int fd);
char		**split_rgb(char *color);
int			load_textures(t_game *game);
void		destroy_images(t_game *g);
t_texture	*select_texture(t_game *game, t_ray *ray);
int			calc_tex_x(t_texture *tex, t_ray *ray);
int			init_screen(t_game *game);
int			render_frame(t_game *game);
void		init_ray(t_game *game, t_ray *ray, int x);
void		init_ray_steps(t_game *game, t_ray *ray);
void		perform_dda(t_game *game, t_ray *ray);
void		calc_wall_distance(t_ray *ray);
void		calc_wall_x(t_game *game, t_ray *ray);
void		calc_wall_slice(t_game *game, t_ray *ray, t_wall *wall);
void		move_player(t_game *game, double move, int strafe);
void		rotate_player(t_game *game, double angle);
int			game_loop(t_game *game);
void		init_ray_steps(t_game *game, t_ray *ray);
void		apply_movement(t_game *game);
void		free_config(t_config *config);
void		cleanup_game(t_game *game);

#endif
