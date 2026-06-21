#include "../include/cub3d.h"

static int	can_move_to(t_game *game, double x, double y)
{
	if (game->map.grid[(int)y][(int)(x + COL_BUF)] == '1')
		return (0);
	if (game->map.grid[(int)y][(int)(x - COL_BUF)] == '1')
		return (0);
	if (game->map.grid[(int)(y + COL_BUF)][(int)x] == '1')
		return (0);
	if (game->map.grid[(int)(y - COL_BUF)][(int)x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, double move, int strafe)
{
	double	move_x;
	double	move_y;
	double	new_x;
	double	new_y;

	if (strafe)
	{
		move_x = -game->player.dir_y;
		move_y = game->player.dir_x;
	}
	else
	{
		move_x = game->player.dir_x;
		move_y = game->player.dir_y;
	}
	new_x = game->player.pos_x + move_x * move;
	new_y = game->player.pos_y + move_y * move;
	if (can_move_to(game, new_x, game->player.pos_y))
		game->player.pos_x = new_x;
	if (can_move_to(game, game->player.pos_x, new_y))
		game->player.pos_y = new_y;
}
