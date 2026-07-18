/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 17:56:11 by mmustone          #+#    #+#             */
/*   Updated: 2026/07/15 15:10:53 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
		i++;
	return (line[i] == '\0');
}

int	is_config_line(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int	handle_parse_status(int fd, int status)
{
	if (status == 1)
	{
		drain_file(fd);
		close(fd);
		return (1);
	}
	if (status == 2)
	{
		drain_file(fd);
		return (2);
	}
	return (0);
}

char	**split_rgb(char *color)
{
	char	**rgb;
	int		i;
	int		commas;

	i = 0;
	commas = 0;
	while (color[i])
	{
		if (color[i] == ',')
			commas++;
		i++;
	}
	if (commas != 2)
		return (printf("Error\nInvalid RGB format\n"), NULL);
	rgb = ft_split(color, ',');
	if (!rgb)
		printf("Error\nFailed to allocate RGB values\n");
	return (rgb);
}
