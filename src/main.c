/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:19:24 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/10 17:50:34 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	check_cub_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (0);
	if (ft_strncmp(filename + len - 4, ".cub", 4) != 0)
		return (0);
	return (1);
}

int	handle_args(int ac, char **av, t_game *game)
{
	if (ac != 2 || !check_cub_extension(av[1]))
	{
		ft_printf("Error\nUsage: %s <map_file.cub>\n", av[0]);
		return (1);
	}
	ft_memset(game, 0, sizeof(*game));
	game->vars.win_height = 500;
	game->vars.win_width = 1000;
	return (0);
}

int	setup_mlx(t_game *game)
{
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
		return (0);
	game->vars.win = mlx_new_window(game->vars.mlx, game->vars.win_width,
			game->vars.win_height, "CUB 3D");
	if (!game->vars.win)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_game	game;

	printf("Cub3d: Loading ...\n");
	if (handle_args(ac, av, &game))
		return (1);
	if (!setup_mlx(&game))
		return (1);
	hook(&game);
	mlx_loop(game.vars.mlx);
	return (0);
}
