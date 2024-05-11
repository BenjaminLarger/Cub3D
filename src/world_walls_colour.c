/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/05/11 17:10:01 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	pack_rgba(uint8_t pixels[4])
{
	uint32_t	color;

	color = 0;
	color |= ((uint32_t)pixels[0] << 24);
	color |= ((uint32_t)pixels[1] << 16);
	color |= ((uint32_t)pixels[2] << 8);
	color |= pixels[3];
	return (color);
}

uint32_t	get_colour_from_texture(double ratio_x, double calc_h,
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

uint32_t	get_col_px_colour(double calc_h, t_data *data, t_pfv pfv)
{
	unsigned int	colour;

	if (pfv.wall_y > data->player_y
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.0001)
		colour = get_colour_from_texture(1 - pfv.wall_x + (int)pfv.wall_x,
				calc_h, data->wall_no);
	else if (pfv.wall_y < data->player_y
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.0001)
		colour = get_colour_from_texture(pfv.wall_x - (int)pfv.wall_x,
				calc_h, data->wall_so);
	else if (pfv.wall_x > data->player_x
		&& fabs(pfv.wall_x - round(pfv.wall_x)) < 0.0001)
		colour = get_colour_from_texture(pfv.wall_y - (int)pfv.wall_y,
				calc_h, data->wall_ea);
	else if (pfv.wall_x < data->player_x
		&& fabs(pfv.wall_x - round(pfv.wall_x)) < 0.0001)
		colour = get_colour_from_texture(1 - pfv.wall_y + (int)pfv.wall_y,
				calc_h, data->wall_we);
	else
		colour = 0x33333388;
	return (colour);
}
