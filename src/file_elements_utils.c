/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:02 by demre             #+#    #+#             */
/*   Updated: 2024/05/16 11:56:18 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialise_rgb_variables(t_rgb *rgb)
{
	rgb->r = 0;
	rgb->g = 0;
	rgb->b = 0;
	rgb->index = 0;
	rgb->i = 0;
	rgb->comma_count = 0;
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

static void	handle_commas(t_rgb *rgb)
{
	rgb->i++;
	rgb->comma_count++;
	if (rgb->comma_count > 2)
		print_and_exit("Wrong RGB data", 2, EXIT_FAILURE);
}

unsigned int	rgb_to_hex(char *rgb_str)
{
	t_rgb	rgb;

	initialise_rgb_variables(&rgb);
	while (rgb_str[rgb.i])
	{
		if (rgb_str[rgb.i] >= '0' && rgb_str[rgb.i] <= '9')
		{
			rgb.num = 0;
			while (rgb_str[rgb.i] >= '0' && rgb_str[rgb.i] <= '9')
			{
				rgb.num = rgb.num * 10 + (rgb_str[rgb.i] - '0');
				rgb.i++;
			}
			if (rgb.num > 255)
				print_and_exit("Wrong RGB data", 2, EXIT_FAILURE);
			assign_rgb_value(&rgb);
			rgb.index++;
		}
		else if (rgb_str[rgb.i] == ',' && rgb.i != 0)
			handle_commas(&rgb);
		else
			print_and_exit("Wrong RGB data", 2, EXIT_FAILURE);
	}
	return ((uint32_t)(rgb.r << 24) | (uint32_t)(rgb.g << 16)
		| (uint32_t)(rgb.b << 8) | 0xFF);
}
