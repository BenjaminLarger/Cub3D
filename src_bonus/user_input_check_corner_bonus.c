/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_check_corner_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 21:01:40 by blarger           #+#    #+#             */
/*   Updated: 2024/05/14 10:05:41 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief This function check if the player is moving toward
 *  a corner identified as blocked.
 * @return true if the player is moving toward a blocked corner.
 */

static double	player_move_into_corner(t_data *data, t_corner *corner,
	double x, double y)
{
	if (ceil(y) < ceil(data->player_y) && ceil(x) < ceil(data->player_x)
		&& corner->north_west_blocked == true)
	{
		return (true);
	}
	if (ceil(y) < ceil(data->player_y) && floor(x) > floor(data->player_x)
		&& corner->north_est_blocked == true)
	{
		return (true);
	}
	if (floor(y) > floor(data->player_y) && ceil(x) < ceil(data->player_x)
		&& corner->south_west_blocked == true)
	{
		return (true);
	}
	if (floor(y) > floor(data->player_y) && floor(x) > floor(data->player_x)
		&& corner->south_est_blocked == true)
	{
		return (true);
	}
	return (false);
}

/**
 * @brief This function update the corners blocked the current player area.
 *
 * @return true if their is at least one corner within the player current area.
 */
static double	check_deadlock_corner(t_data *data, t_corner *corner)
{
	int			x;
	int			y;

	x = (int)data->player_x;
	y = (int)data->player_y;
	if (data->map[y + 1][x] == '1'
		&& data->map[y][x + 1] == '1')
		corner->south_est_blocked = true;
	if (data->map[y + 1][x] == '1' && data->map[y][x - 1] == '1')
		corner->south_west_blocked = true;
	if (data->map[y - 1][x] == '1'
		&& data->map[y][x + 1] == '1')
		corner->north_est_blocked = true;
	if (data->map[y - 1][x] == '1' && data->map[y][x - 1] == '1')
		corner->north_west_blocked = true;
	if (corner->north_est_blocked == true
		|| corner->north_west_blocked == true
		|| corner->south_est_blocked == true
		|| corner->south_west_blocked == true)
		return (true);
	else
		return (false);
}

/**
 * @brief This function check if the player is moving toward a corner.
 *
 * @param x The x aimed position.
 * @param y The y aimed position.
 * @return true if the player is moving toward a corner.
 */
bool	move_in_corner(t_data *data, double x, double y)
{
	t_corner	corner;

	corner.north_est_blocked = false;
	corner.north_west_blocked = false;
	corner.south_est_blocked = false;
	corner.south_west_blocked = false;
	if (fabs(x - round(x)) > 0.25 || fabs(y - round(y)) > 0.25)
	{
		return (false);
	}
	if (check_deadlock_corner(data, &corner) == false)
		return (false);
	if (player_move_into_corner(data, &corner, x, y) == true)
		return (true);
	else
		return (false);	
}
