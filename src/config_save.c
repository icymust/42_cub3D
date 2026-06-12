/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:04:06 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 18:46:53 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	remove_newline(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

static int	save_texture(char **dst, char *path)
{
	if (*dst)
		return (1);
	remove_newline(path);
	*dst = ft_strdup(path);
	if (!*dst)
		return (1);
	return (0);
}

int	config_save(t_config *config, char *line)
{
	if (ft_strncmp(line, "NO", 2) == 0 && line[2] == ' ')
		return (save_texture(&config->no, line + 3));
	else if (ft_strncmp(line, "SO", 2) == 0 && line[2] == ' ')
		return (save_texture(&config->so, line + 3));
	else if (ft_strncmp(line, "WE", 2) == 0 && line[2] == ' ')
		return (save_texture(&config->we, line + 3));
	else if (ft_strncmp(line, "EA", 2) == 0 && line[2] == ' ')
		return (save_texture(&config->ea, line + 3));
	else if (ft_strncmp(line, "F", 1) == 0 && line[1] == ' ')
		return (parse_color(&config->floor_color, &config->has_floor, line
				+ 2));
	else if (ft_strncmp(line, "C", 1) == 0 && line[1] == ' ')
		return (parse_color(&config->ceiling_color, &config->has_ceiling, line
				+ 2));
	return (0);
}
