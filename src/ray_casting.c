/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:25:29 by blarger           #+#    #+#             */
/*   Updated: 2024/05/11 12:26:37 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	find_horizontal_intersection(t_data *data, double ray_angle)
{
	t_map	map;

	get_slope_info(data, &map, ray_angle);
	if (sin(ray_angle) > 0)
	{
		//printf("\033[31mFACING DOWN, sin(ray_angle) = %f\033[0m\n", sin(ray_angle));
		map.old_y = floor(data->player_y) + 1; //Here, we chose to make A part of the block above the line, that is why we subtract 1 from A.y
		map.ya = 1 + 0.000000000000001;
	}
	else
	{
		//printf("\033[31mFACING UP, sin(ray_angle) = %f\033[0m\n", sin(ray_angle));
		map.old_y = floor(data->player_y);
		map.ya = -1 + 0.000000000000001;
	}
	map.old_x = (map.old_y - map.b) / map.m;
	//printf ("ray_angle = %f, tan(ray_angle) = %f, YA = %f\n",ray_angle, tan(ray_angle), map.ya);
	adjust_extrem_value(&map, data);
	map.len = sqrt(pow(map.old_x - data->player_x, 2) + pow(map.old_y - data->player_y, 2));
	//printf ("Xedge: old_x = %f\told_y = %f\tlen = %f\n", map.old_x, map.old_y, map.len);
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
		//printf("\033[32mFACING LEFT, cos(ray_angle) = %f\033[0m\n", cos(ray_angle));
		map.old_x = floor(data->player_x);
		map.xa = -1 - 0.0001;
	}
	else
	{
		//printf("\033[32mFACING RIGHT, cos(ray_angle) = %f\033[0m\n", cos(ray_angle));
		map.old_x = floor(data->player_x) + 1;
		map.xa = 1 + 0.000000000000001;
	}
	map.old_y = map.old_x * map.m + map.b;
	adjust_extrem_value(&map, data);
	map.len = sqrt(pow(map.old_x - data->player_x, 2) + pow(map.old_y - data->player_y, 2));
	//printf ("Yedge: old_x = %f\t, old_y = %f, lenb = %f, xa = %f, \n", map.old_x, map.old_y, map.len, map.xa);
	return (find_vertical_wall_loop(data, &map, ray_angle));
}

double	get_line_length_draft(t_data *data, double ray_angle)
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
	//distance_to_wall *= cos(ray_angle - data->player_angle);
	distance_to_wall = round(distance_to_wall * 100) / 100;
	//printf("\033[1;34mshortest distance_to_wall = %f\n\033[0m", distance_to_wall);
	//printf("----------\n");
	return (distance_to_wall);
}
