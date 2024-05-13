/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:42:18 by blarger           #+#    #+#             */
/*   Updated: 2024/05/13 15:48:32 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	can_move(char point)
{
	if (point == WALL || point == '2')
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
/* static bool	keep_distance_with_wall(t_data *data, double x, double y)
{
	printf("sin(player_angle) = %f\n", sin(data->player_angle));
	if (sin(data->player_angle < 0))
	{
		printf("looking at north\n");
		if (data->map[(int)(y - 0.3)][(int)x] == WALL || data->map[(int)(y - 0.3)][(int)x] == '2')
		{
			printf("too close of north wall\n");
			return (false);
		}
	}
	if (sin(data->player_angle > 0))
	{
		printf("looking at south\n");
		if (data->map[(int)(y + 0.3)][(int)x] == WALL || data->map[(int)(y + 0.3)][(int)x] == '2')
		{
			printf("too close of south wall\n");
			return (false);
		}
	}
	if (cos(data->player_angle) > 0)
	{
		if (data->map[(int)y][(int)(x + 0.3)] == WALL || data->map[(int)y][(int)x] == '2')
		{
			printf("too close of est wall\n");
			return (false);
		}
	}
	else if (cos(data->player_angle) < 0)
	{
		if (data->map[(int)y][(int)(x - 0.3)] == WALL || data->map[(int)y][(int)x] == '2')
		{
			printf("too close of west wall\n");
			return (false);
		}
	}
	return (true);
} */

bool	player_can_move(t_data *data, double end_x, double end_y)
{
	double	x;
	double	y;

	x = data->player_x + end_x;
	y = data->player_y + end_y;
	/* if (sin(data->player_angle > 0))
		y -= 0.2;
	else if (sin(data->player_angle < 0))
		y += 0.2;
	if (cos(data->player_angle) > 0)
		x += 0.2;
	else if (cos(data->player_angle) < 0)
		x -= 0.2; */
	printf("x = %f, y = %f\n", x, y);
	if (move_in_corner(data, x, y) == true)
		return (false);
	if (data->map[(int)y][(int)x] == WALL || data->map[(int)y][(int)x] == '2')
		return (false);
	else
		return (true);
	//return (keep_distance_with_wall(data, x, y));
}

