/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:44:28 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 13:03:10 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		win_width;
	int		win_height;
}			t_vars;

typedef struct player
{
	int			pos_x;
	int			pos_y;
	int			steps;
}				t_player;

typedef struct s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		spawn;
}			t_map;

typedef struct s_game
{
	t_vars	vars;
	t_map	map;
	t_player	player;
}			t_game;

void		hook(t_game *game);
int			close_win(t_game *game);
int			count_lines(const char *filename);
int			read_grid(t_map *map, const char *filename, int height);
int			map_name_check(const char *filename);
int			map_load(t_map *map, char *filename);
void		free_map(t_map *map);
int			grid_check(t_map *m);
int	find_player(t_map *m, int *sy, int *sx);

#endif