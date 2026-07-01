#include "../include/cub3d_bonus.h"

static int	get_map_color(t_game *game, t_pos map)
{
	if (map.y < 0 || map.y >= game->map.height)
		return (-1);
	if (map.x < 0 || map.x >= (int)ft_strlen(game->map.grid[map.y]))
		return (-1);
	if (game->map.grid[map.y][map.x] == '1')
		return (MM_WALL_COLOR);
	if (game->map.grid[map.y][map.x] == '0'
		|| game->map.grid[map.y][map.x] == 'N'
		|| game->map.grid[map.y][map.x] == 'S'
		|| game->map.grid[map.y][map.x] == 'E'
		|| game->map.grid[map.y][map.x] == 'W')
		return (MM_FLOOR_COLOR);
	return (-1);
}

static void	draw_tile(t_game *game, t_pos screen, int color)
{
	t_pos	pixel;

	pixel.y = 0;
	while (pixel.y < MM_TILE)
	{
		pixel.x = 0;
		while (pixel.x < MM_TILE)
		{
			if (screen.x + pixel.x >= MM_X && screen.x + pixel.x < MM_X
				+ MM_SIZE && screen.y + pixel.y >= MM_Y && screen.y
				+ pixel.y < MM_Y + MM_SIZE)
				put_pixel(&game->screen, screen.x + pixel.x, screen.y + pixel.y,
					color);
			pixel.x++;
		}
		pixel.y++;
	}
}

static void	draw_player(t_game *game)
{
	t_pos	center;
	t_pos	start;
	t_pos	pixel;

	center.x = MM_X + MM_SIZE / 2;
	center.y = MM_Y + MM_SIZE / 2;
	start.x = center.x - MM_PLAYER_WIDTH / 2;
	start.y = center.y - MM_PLAYER_HEIGHT / 2;
	pixel.y = 0;
	while (pixel.y <= MM_PLAYER_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x <= MM_PLAYER_WIDTH)
		{
			put_pixel(&game->screen, start.x + pixel.x, start.y + pixel.y,
				MM_PLAYER_COLOR);
			pixel.x++;
		}
		pixel.y++;
	}
}

static void	draw_map_cell(t_game *game, t_pos delta, t_pos offset)
{
	t_pos	map;
	t_pos	screen;
	int		color;

	map.x = (int)game->player.pos_x + delta.x;
	map.y = (int)game->player.pos_y + delta.y;
	color = get_map_color(game, map);
	if (color == -1)
		return ;
	screen.x = MM_X + MM_SIZE / 2 + delta.x * MM_TILE + offset.x;
	screen.y = MM_Y + MM_SIZE / 2 + delta.y * MM_TILE + offset.y;
	draw_tile(game, screen, color);
}

void	draw_minimap(t_game *game)
{
	t_pos	delta;
	t_pos	offset;

	offset.x = ((int)game->player.pos_x - game->player.pos_x) * MM_TILE;
	offset.y = ((int)game->player.pos_y - game->player.pos_y) * MM_TILE;
	delta.y = -MM_RADIUS;
	while (delta.y <= MM_RADIUS)
	{
		delta.x = -MM_RADIUS;
		while (delta.x <= MM_RADIUS)
		{
			draw_map_cell(game, delta, offset);
			delta.x++;
		}
		delta.y++;
	}
	draw_player(game);
}
