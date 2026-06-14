/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martinmust <martinmust@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:05:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/14 22:59:27 by martinmust       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_rgb_valid(int r, int g, int b)
{
	int	status;

	status = 0;
	if (r < 0 || r > 255)
		status = 1;
	if (g < 0 || g > 255)
		status = 1;
	if (b < 0 || b > 255)
		status = 1;
	if (status)
		printf("Error\nRGB values must be between 0 and 255\n");
	return (status);
}

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

static int	is_valid_number(char *s)
{
	int	i;
	int	has_digit;

	i = 0;
	has_digit = 0;
	while (s[i] == ' ')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		has_digit = 1;
		i++;
	}
	while (s[i] == ' ' || s[i] == '\n')
		i++;
	if (!has_digit || s[i] != '\0')
		return (0);
	return (1);
}

static int	check_rgb_format(char **rgb)
{
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		printf("Error\nInvalid RGB format\n");
		free_split(rgb);
		return (1);
	}
	if (!is_valid_number(rgb[0]) || !is_valid_number(rgb[1])
		|| !is_valid_number(rgb[2]))
	{
		printf("Error\nRGB values must contain only digits\n");
		free_split(rgb);
		return (1);
	}
	return (0);
}

int	parse_color(int *dst, int *has_color, char *color)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	if (*has_color)
	{
		printf("Error\nDuplicate color configuration\n");
		return (1);
	}
	rgb = split_rgb(color);
	if (!rgb)
		return (1);
	if (check_rgb_format(rgb))
		return (1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_split(rgb);
	if (is_rgb_valid(r, g, b))
		return (1);
	*dst = rgb_to_int(r, g, b);
	*has_color = 1;
	return (0);
}
