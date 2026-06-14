/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:04:06 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/14 22:47:55 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	trim_texture_path(char *s)
{
	int	len;

	len = ft_strlen(s);
	while (len > 0 && (s[len - 1] == ' ' || s[len - 1] == '\t' || s[len
			- 1] == '\n'))
	{
		s[len - 1] = '\0';
		len--;
	}
}

static int	check_xpm_extension(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (len < 4 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		printf("Error\nTexture file must have .xpm extension\n");
		return (1);
	}
	return (0);
}

static int	save_texture(char **dst, char *path)
{
	if (*dst)
	{
		printf("Error\nDuplicate texture configuration\n");
		return (1);
	}
	while (*path == ' ' || *path == '\t')
		path++;
	trim_texture_path(path);
	if (check_xpm_extension(path))
		return (1);
	*dst = ft_strdup(path);
	if (!*dst)
	{
		printf("Error\nFailed to allocate memory for texture path\n");
		return (1);
	}
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
