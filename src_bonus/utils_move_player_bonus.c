/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:42:18 by blarger           #+#    #+#             */
/*   Updated: 2024/05/15 15:47:09 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	can_move(char point)
{
	if (point == WALL || point == '2' || point == 'C')
	{
		return (false);
	}
	else
		return (true);
}

bool	is_wall(t_map *map, t_data *data, double ray_angle)
{
	double	x;
	double	y;

	x = map->new_x;
	y = map->new_y;
	if (sin(ray_angle) > 0)
		y += INC;
	else if (sin(ray_angle) < 0)
		y -= INC;
	if (cos(ray_angle) > 0)
		x += INC;
	else if (cos(ray_angle) < 0)
		x -= INC;
	if (can_move(data->map[(int)y][(int)x]) == false)
		return (true);
	else
		return (false);
}

bool	player_can_move(t_data *data, double end_x, double end_y)
{
	double	x;
	double	y;

	x = data->player_x + end_x;
	y = data->player_y + end_y;
	if (move_in_corner(data, x, y) == true)
		return (false);
	if (data->map[(int)y][(int)x] == WALL || data->map[(int)y][(int)x] == '2'
		|| data->map[(int)y][(int)x] == DOOR_CLOSED)
		return (false);
	else
		return (true);
}

