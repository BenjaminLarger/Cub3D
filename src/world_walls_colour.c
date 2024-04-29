/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/04/29 18:47:02 by demre            ###   ########.fr       */
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

uint32_t	get_colour_from_texture(double wall_x, double calc_y,
	mlx_texture_t *texture)
{
	uint32_t	index;
	uint8_t		rgba[4];
	int			i;
	uint32_t	x;
	uint32_t	y;
	
	x = (uint32_t)(texture->width * wall_x);
//	y = (uint32_t)(texture->height * (wall_y - (int)wall_y));
	y = (uint32_t)(texture->height * (calc_y / 100));
//	printf("get_colour_from_texture (%f, %f) (%u, %u)\n", wall_x, calc_y, x, y);
	if (!texture || !texture->pixels
		|| x >= texture->width || y >= texture->height)
		return (0);
	index = (y * texture->width + x) * texture->bytes_per_pixel;
	i = 0;
	while (i < 4)
	{
		rgba[i] = texture->pixels[index + i];
		i++;
	}
	return (pack_rgba(rgba));
}

uint32_t	get_col_px_colour(uint32_t y, t_data *data, t_pfv pfv)
{
	unsigned int	colour;

	if (fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01) // corners
	{
		if (pfv.wall_y > data->player_y)
			colour = 0xff00ffFF; // Facing north face Magenta
		else if (pfv.wall_y < data->player_y)
			colour = 0x00ff00FF; // Facing south face Green1
		else
			colour = 0x000000FF;
	}
	else if (pfv.wall_y > data->player_y && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01)
		colour = get_colour_from_texture(1 - pfv.wall_x + (int)pfv.wall_x, y, data->wall_no);
	else if (pfv.wall_y < data->player_y && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01)
		colour = get_colour_from_texture(pfv.wall_x - (int)pfv.wall_x, y, data->wall_so);
	else if (pfv.wall_x > data->player_x && fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01)
		colour = 0xd5b6d5FF; // Facing east face
	else if (pfv.wall_x < data->player_x && fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01)
		colour = 0x9bd0b7FF; // Facing west face
	else
		colour = 0x000000FF;
	return (colour);
}
