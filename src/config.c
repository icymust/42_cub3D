/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 16:49:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 18:44:43 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	config_check_complete(t_config *config)
{
	if (!config->no || !config->so || !config->we || !config->ea)
		return (1);
	if (!config->has_floor || !config->has_ceiling)
		return (1);
	return (0);
}

static int	handle_config_line(t_config *config, char *line)
{
	if (is_empty_line(line))
		return (0);
	if (is_config_line(line))
		return (config_save(config, line));
	if (is_map_line(line))
		return (2);
	return (1);
}

void	drain_file(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
}

int	config_parse(t_config *config, char *filename)
{
	int		fd;
	int		status;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		status = handle_config_line(config, line);
		free(line);
		status = handle_parse_status(fd, status);
		if (status == 1)
			return (1);
		if (status == 2)
			break ;
		line = get_next_line(fd);
	}
	close(fd);
	return (config_check_complete(config));
}
