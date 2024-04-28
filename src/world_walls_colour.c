/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls_colour.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/04/28 15:49:41 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	get_col_px_colour(t_data *data, t_pfv pfv)
{
	unsigned int	colour;

	if (pfv.wall_y > data->player_y && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01)
		colour = 0xf8df81AA;
	else if (pfv.wall_y < data->player_y && fabs(pfv.wall_y - round(pfv.wall_y)) < 0.01)
		colour = 0xf6aa90AA;
	else if (pfv.wall_x > data->player_x && fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01)
		colour = 0xd5b6d5AA;
	else if (pfv.wall_x < data->player_x && fabs(pfv.wall_x - round(pfv.wall_x)) < 0.01)
		colour = 0x9bd0b7AA;
	else
		colour = 0x000000AA;
	return (colour);
}
