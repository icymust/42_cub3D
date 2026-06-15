/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:44:28 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/15 12:04:56 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
}				t_vars;

typedef struct s_player
{
	int			pos_x;
	int			pos_y;
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
}				t_game;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

void			hook(t_game *game);
int				close_win(t_game *game);
int				count_map_lines(const char *filename);
int				read_grid(t_map *map, const char *filename, int height);
int				map_name_check(const char *filename);
int				map_load(t_map *map, char *filename);
void			free_map(t_map *map);
int				grid_check(t_map *m);
int				find_player(t_map *m, int *sy, int *sx);
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

#endif
