/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/04/28 17:04:38 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_col_px_colour(t_data *data, t_pfv pfv)
{
	unsigned int	colour;

	if (fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01
		&& fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01) // corners
	{
		if (pfv.wall_y > data->player_y)
			colour = 0xff00ffFF; // Facing north face Magenta
		else if (pfv.wall_y < data->player_y)
			colour = 0x00ff00FF; // Facing south face Green1
		else if (pfv.wall_x > data->player_x)
			colour = 0xffff00FF; // Facing east face Yellow1
		else if (pfv.wall_x < data->player_x)
			colour = 0x0000ffFF; // Facing west face Blue1
		else
			colour = 0x000000FF;
	}
	else if (pfv.wall_y > data->player_y && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01)
		colour = 0xf8df81FF; // Facing north face
	else if (pfv.wall_y < data->player_y && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01)
		colour = 0xf6aa90FF; // Facing south face
	else if (pfv.wall_x > data->player_x && fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01)
		colour = 0xd5b6d5FF; // Facing east face
	else if (pfv.wall_x < data->player_x && fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01)
		colour = 0x9bd0b7FF; // Facing west face
	else
		colour = 0x000000FF;
	return (colour);
}
