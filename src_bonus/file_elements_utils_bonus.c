/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:02 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 15:46:40 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	initialise_rgb_variables(t_rgb *rgb)
{
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
	rgb->index = 0;
	rgb->num = 0;
}

static void	assign_rgb_value(t_rgb *rgb)
{
	if (rgb->index == 0)
		rgb->r = rgb->num;
	else if (rgb->index == 1)
		rgb->g = rgb->num;
	else if (rgb->index == 2)
		rgb->b = rgb->num;
}

unsigned int	rgb_to_hex(char *rgb_str)
{
	t_rgb	rgb;

	initialise_rgb_variables(&rgb);
	while (*rgb_str)
	{
		if (*rgb_str >= '0' && *rgb_str <= '9')
		{
			rgb.num = 0;
			while (*rgb_str >= '0' && *rgb_str <= '9')
			{
				rgb.num = rgb.num * 10 + (*rgb_str - '0');
				rgb_str++;
			}
			assign_rgb_value(&rgb);
			if (*rgb_str == ',')
				rgb_str++;
			rgb.index++;
		}
		else
			rgb_str++;
	}
	return ((uint32_t)(rgb.r << 24) | (uint32_t)(rgb.g << 16)
		| (uint32_t)(rgb.b << 8) | 0xFF);
}
