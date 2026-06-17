/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 13:19:24 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/16 16:01:31 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	handle_args_and_map(int ac, char **av, t_game *game)
{
	if (ac != 2)
	{
		ft_printf("Error\nUsage: %s <map_file.cub>\n", av[0]);
		return (1);
	}
	ft_memset(game, 0, sizeof(*game));
	if (map_name_check(av[1]))
		return (1);
	if (config_parse(&game->config, av[1]))
		return (1);
	if (map_load(&game->map, av[1]))
		return (1);
	game->vars.win_height = WIN_HEIGHT;
	game->vars.win_width = WIN_WIDTH;
	return (0);
}

static int	setup_mlx(t_game *game)
{
	game->vars.mlx = mlx_init();
	if (!game->vars.mlx)
		return (1);
	game->vars.win = mlx_new_window(game->vars.mlx, game->vars.win_width,
			game->vars.win_height, "CUB 3D");
	if (!game->vars.win)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	printf("Cub3d: Loading ...\n");
	if (handle_args_and_map(ac, av, &game))
		return (1);
	if (setup_mlx(&game))
	{
		free_map(&game.map);
		ft_printf("Error\nFailed to initialize MiniLibX\n");
		return (1);
	}
	if (init_screen(&game))
	{
		free_map(&game.map);
		ft_printf("Error\nFailed to initialize screen image\n");
		return (1);
	}
	if (load_textures(&game))
	{
		destroy_images(&game);
		free_map(&game.map);
		ft_printf("Error\nFailed to load textures\n");
		return (1);
	}
	place_player_and_hook(&game);
	render_frame(&game);
	mlx_loop(game.vars.mlx);
	return (0);
}
