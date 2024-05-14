/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:48:23 by blarger           #+#    #+#             */
/*   Updated: 2024/05/14 19:34:41 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_close_door(t_data *data)
{
	int	x;
	int	y;

	x = (int)data->player_x;
	y = (int)data->player_y;
	if (data->door_is_open == true)
	{
		if (data->map[y - 1][x] == DOOR_OPEN)
		{
			data->map[y - 1][x] = DOOR_CLOSED;
			data->door_is_open = false;
		}
		if (data->map[y + 1][x] == DOOR_OPEN)
		{
			data->map[y + 1][x] = DOOR_CLOSED;
			data->door_is_open = false;
		}
		if (data->map[y][x - 1] == DOOR_OPEN)
		{
			data->map[y][x] = DOOR_CLOSED;
			data->door_is_open = false;
		}
		if (data->map[y][x + 1] == DOOR_OPEN)
		{
			data->map[y][x] = DOOR_CLOSED;
			data->door_is_open = false;
		}
	}
}

void	close_door(t_data *data)
{
	double	x;
	double	y;

	x = data->x_door_op;
	y = data->y_door_op;
	if (data->player_can_open_door == true
		&& data->map[(int)y][(int)x] == DOOR_CLOSED)
	{
		printf("open door data->map[%f][%f] = %c\n", y, x, data->map[(int)y][(int)x]);
		data->map[(int)data->y_door_op][(int)data->x_door_op] = DOOR_OPEN;
		data->player_can_open_door = false;
		data->door_is_open = true;
		if (data->paint_in_render == FALSE)
		{
			paint_world(data);
			paint_minimap(data);
		}
	}
	else
		printf("Failed to locate door\n");//to delete, testing purpose
}

void	check_player_can_open_door(t_data *data, t_pfv pfv)//can delete
{
	if (pfv.i == WIDTH / 2 && pfv.obstacle == DOOR_CLOSED
		&& pfv.ray_length <= 1)
	{
		data->player_can_open_door = true;
		data->x_door_op = pfv.obs_x;
		data->y_door_op = pfv.obs_y;
		//printf("can open door\n");
	}
	else if (pfv.i == WIDTH / 2)
	{
		data->player_can_open_door = false;
	}
}
