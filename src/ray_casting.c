/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:25:29 by blarger           #+#    #+#             */
/*   Updated: 2024/05/14 16:47:34 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	find_horizontal_intersection(t_data *data, double ray_angle, t_pfv pfv)
{
	t_map	map;

	get_slope_info(data, &map, ray_angle);
	if (sin(ray_angle) < 0.0001 && sin(ray_angle) > -0.0001)
		return (2147483647);
	else if (sin(ray_angle) > 0)
	{
		map.old_y = floor(data->player_y) + 1;
		map.ya = 1 + INC2;
	}
	else if (sin(ray_angle) < 0)
	{
		map.old_y = floor(data->player_y);
		map.ya = -1 + INC2;
	}
	map.old_x = (map.old_y - map.b) / map.m;
	adjust_extrem_value(&map, data);
	map.len = sqrt(pow(map.old_x - data->player_x, 2)
			+ pow(map.old_y - data->player_y, 2));
	return (find_horizontal_wall_loop(data, &map, ray_angle, pfv));
}

double	find_vertical_intersection(t_data *data, double ray_angle)
{
	t_map	map;

	get_slope_info(data, &map, ray_angle);
	if (cos(ray_angle) < 0.0001 && cos(ray_angle) > -0.0001)
		return (2147483647);
	else if (cos(ray_angle) < -0)
	{
		map.old_x = floor(data->player_x);
		map.xa = -1 - INC2;
	}
	else if (cos(ray_angle) > 0)
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

double	get_wall_distance(t_data *data, double ray_angle, t_pfv pfv)
{
	double	vertical_distance;
	double	horizontal_distance;
	double	distance_to_wall;

	horizontal_distance = find_horizontal_intersection(data, ray_angle, pfv);
	vertical_distance = find_vertical_intersection(data, ray_angle);
	if (fabs(horizontal_distance) > fabs(vertical_distance))
		distance_to_wall = vertical_distance;
	else
		distance_to_wall = horizontal_distance;
	/* if (pfv.i == 1824 || pfv.i == 1825 || pfv.i == 1826)
	{
		printf("pfv = %d, distance to wall = %f\n",pfv.i, distance_to_wall);
		if (distance_to_wall == horizontal_distance)
			printf("pfv = %d, horizontal distance\n",pfv.i);
		else
			printf("pfv = %d, vertical distance\n",pfv.i);
	} */
	return (distance_to_wall);
}

/* pfv.i == 96 || pfv.i == 672 || pfv.i == 1248 || */
