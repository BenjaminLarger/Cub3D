/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:48:23 by blarger           #+#    #+#             */
/*   Updated: 2024/05/15 12:38:26 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_close_door(t_data *data)
{
	double	door_distance_to_player;

	if (data->door_is_open == true)
	{
		door_distance_to_player = sqrt(pow(data->player_x - data->x_door_op, 2)
				+ pow(data->player_y - data->y_door_op, 2));
		if (door_distance_to_player > 2)
		{
			data->door_is_open = false;
			data->map[(int)data->y_door_op][(int)data->x_door_op] = DOOR_CLOSED;
		}
	}
}

void	open_door(t_data *data)
{
	double	x;
	double	y;

	x = data->x_door_op;
	y = data->y_door_op;
	if (data->player_can_open_door == true
		&& data->map[(int)y][(int)x] == DOOR_CLOSED)
	{
		data->map[(int)data->y_door_op][(int)data->x_door_op] = DOOR_OPEN;
		data->player_can_open_door = false;
		data->door_is_open = true;
		if (data->paint_in_render == FALSE)
		{
			paint_world(data);
			paint_minimap(data);
		}
	}
}

void	check_player_can_open_door(t_data *data, t_pfv pfv)//can delete
{
	if (pfv.i == WIDTH / 2 && pfv.obstacle == DOOR_CLOSED
		&& pfv.ray_length <= 1)
	{
		data->player_can_open_door = true;
		data->x_door_op = pfv.obs_x;
		data->y_door_op = pfv.obs_y;
	}
	else if (pfv.i == WIDTH / 2)
	{
		data->player_can_open_door = false;
	}
}

