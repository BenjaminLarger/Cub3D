/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/04/30 14:46:23 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	pack_rgba(uint8_t pixels[4])
{
	uint32_t	color;

	color = 0;
	color |= (pixels[0] << 24);
	color |= (pixels[1] << 16);
	color |= (pixels[2] << 8);
	color |= pixels[3];
	return (color);
}

uint32_t	get_colour_from_texture(double wall_x, double calc_h,
	mlx_texture_t *texture)
{
	uint32_t	index;
	uint8_t		rgba[4];
	int			i;
	double	texture_x;
	double	texture_y;

	texture_x = texture->width * wall_x;
//	texture_y = (uint32_t)(texture->height * (wall_y - (int)wall_y));
	texture_y = texture->height * (calc_h / 100);
//	printf("get_colour_from_texture (%f, %f) (%f, %f)\n", wall_x, calc_h, x, y);
	if (!texture || !texture->pixels
		|| (uint32_t)texture_x >= texture->width || (uint32_t)texture_y >= texture->height)
		return (0);
	index = (round(texture_y) * texture->width + round(texture_x)) * texture->bytes_per_pixel;
	i = 0;
	while (i < 4)
	{
		rgba[i] = texture->pixels[index + i];
		i++;
	}
	return (pack_rgba(rgba));
}

uint32_t	get_col_px_colour(uint32_t calc_h, t_data *data, t_pfv pfv)
{
	unsigned int	colour;

	/* if (fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01) // corners
	{
		if (pfv.wall_y > data->player_y)
			colour = 0xff00ffFF; // Facing north face Magenta
		else if (pfv.wall_y < data->player_y)
			colour = 0x00ff00FF; // Facing south face Green1
		else
			colour = 0x000000FF;
	}
	else  */if (pfv.wall_y > data->player_y && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01)
		colour = get_colour_from_texture(1 - pfv.wall_x + (int)pfv.wall_x, calc_h, data->wall_no);
	else if (pfv.wall_y < data->player_y && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01)
		colour = get_colour_from_texture(pfv.wall_x - (int)pfv.wall_x, calc_h, data->wall_so);
	else if (pfv.wall_x > data->player_x && fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01)
		colour = get_colour_from_texture(pfv.wall_y - (int)pfv.wall_y, calc_h, data->wall_ea);
	else if (pfv.wall_x < data->player_x && fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01)
		colour = get_colour_from_texture(1 - pfv.wall_y + (int)pfv.wall_y, calc_h, data->wall_we);
	else
		colour = 0x000000FF;
	return (colour);
}
