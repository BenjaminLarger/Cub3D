/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_door_colour_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/05/14 17:11:53 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static uint32_t	get_colour_from_texture(double ratio_x, double calc_h,
	mlx_texture_t *texture)
{
	uint32_t		index;
	uint8_t			rgba[4];
	unsigned int	i;

	if (!texture || !texture->pixels || ratio_x >= 1 || calc_h >= 1)
		return (0);
	index = ((uint32_t)(texture->height * calc_h) * texture->width
			+ (uint32_t)(texture->width * ratio_x))
		* texture->bytes_per_pixel;
	i = 0;
	while (i < 4)
	{
		rgba[i] = texture->pixels[index + i];
		i++;
	}
	return (pack_rgba(rgba));
}

uint32_t	get_col_px_colour_door(double calc_h, t_data *data, t_pfv pfv,
	mlx_texture_t *door_state)
{
	if (pfv.i != 0 && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.00001
		&& fabs(pfv.wall_x - round(pfv.wall_x)) < 0.00001)
	{
		pfv.wall_x = pfv.wall_x_n1;
		pfv.wall_y = pfv.wall_y_n1;
	}
	if (pfv.wall_y > data->player_y
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.00001)
		return (get_colour_from_texture(1 - pfv.wall_x + (int)pfv.wall_x,
				calc_h, door_state));
	else if (pfv.wall_y < data->player_y
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.00001)
		return (get_colour_from_texture(pfv.wall_x - (int)pfv.wall_x,
				calc_h, door_state));
	else if (pfv.wall_x > data->player_x
		&& fabs(pfv.wall_x - round(pfv.wall_x)) < 0.00001)
		return (get_colour_from_texture(pfv.wall_y - (int)pfv.wall_y,
				calc_h, door_state));
	else if (pfv.wall_x < data->player_x
		&& fabs(pfv.wall_x - round(pfv.wall_x)) < 0.00001)
		return (get_colour_from_texture(1 - pfv.wall_y + (int)pfv.wall_y,
				calc_h, door_state));
	else
		return (0x33333388);
}
