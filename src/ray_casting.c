/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:25:29 by blarger           #+#    #+#             */
/*   Updated: 2024/05/11 14:32:53 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	find_horizontal_intersection(t_data *data, double ray_angle)
{
	t_map	map;

	get_slope_info(data, &map, ray_angle);
	if (sin(ray_angle) > 0)
	{
		map.old_y = floor(data->player_y) + 1;
		map.ya = 1 + INC2;
	}
	else
	{
		map.old_y = floor(data->player_y);
		map.ya = -1 + INC2;
	}
	map.old_x = (map.old_y - map.b) / map.m;
	adjust_extrem_value(&map, data);
	map.len = sqrt(pow(map.old_x - data->player_x, 2)
			+ pow(map.old_y - data->player_y, 2));
	if (can_move(data->map[(int)map.old_y][(int)map.old_x]) == false)
		return (map.len);
	else
		return (find_horizontal_wall_loop(data, &map, ray_angle));
}

double	find_vertical_intersection(t_data *data, double ray_angle)
{
	t_map	map;

	get_slope_info(data, &map, ray_angle);
	if (cos(ray_angle) <= 0)
	{
		map.old_x = floor(data->player_x);
		map.xa = -1 - INC2;
	}
	else
	{
		map.old_x = floor(data->player_x) + 1;
		map.xa = 1 + INC2;
	}
	map.old_y = map.old_x * map.m + map.b;
	adjust_extrem_value(&map, data);
	map.len = sqrt(pow(map.old_x - data->player_x, 2)
			+ pow(map.old_y - data->player_y, 2));
	return (find_vertical_wall_loop(data, &map, ray_angle));
}

double	get_wall_distance(t_data *data, double ray_angle/* , bool fix_fish_eye */)
{
	double	vertical_distance;
	double	horizontal_distance;
	double	distance_to_wall;

	horizontal_distance = find_horizontal_intersection(data, ray_angle);
	vertical_distance = find_vertical_intersection(data, ray_angle);
	if (fabs(horizontal_distance) > fabs(vertical_distance))
		distance_to_wall = vertical_distance;
	else
		distance_to_wall = horizontal_distance;
	/* if (fix_fish_eye == true)
		distance_to_wall *= cos(ray_angle - data->player_angle); */
	return (distance_to_wall);
}
	//distance_to_wall *= cos(ray_angle - data->player_angle);
	//distance_to_wall = round(distance_to_wall * 100) / 100;