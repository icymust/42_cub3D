/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmustone <mmustone@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 18:05:02 by mmustone          #+#    #+#             */
/*   Updated: 2026/06/12 18:26:36 by mmustone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	is_rgb_valid(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (0);
	if (g < 0 || g > 255)
		return (0);
	if (b < 0 || b > 255)
		return (0);
	return (1);
}

static int	rgb_to_int(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	parse_color(int *dst, int *has_color, char *color)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	if (*has_color)
		return (1);
	rgb = ft_split(color, ',');
	if (!rgb)
		return (1);
	if (!rgb[0] || !rgb[1] || !rgb[2] || rgb[3])
	{
		free_split(rgb);
		return (1);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_split(rgb);
	if (!is_rgb_valid(r, g, b))
		return (1);
	*dst = rgb_to_int(r, g, b);
	*has_color = 1;
	return (0);
}
