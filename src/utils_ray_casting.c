/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:07:48 by blarger           #+#    #+#             */
/*   Updated: 2024/05/11 11:07:50 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_slope_info(t_data *data, t_map *map, double ray_angle)
{
	double	x1;
	double	y1;

	x1 = data->player_x + cos(ray_angle) * 0.1 + 0.000000001;
	y1 = data->player_y + sin(ray_angle) * 0.1 + 0.000000001;
	/* if (x1 - data->player_x != 0)
		 */map->m = (y1 - data->player_y) / (x1 - data->player_x);
	/* else if (data->map[map])
	else
		map->m = 1E10; */
	map->b = data->player_y - map->m * data->player_x;
}

void	adjust_extrem_value(t_map *map, t_data *data)
{
	if (map->old_x <= 1)
		map->old_x = 0.999999999999999;
	if (map->old_x > data->col - 0.999999999999999)
		map->old_x = data->col - 0.999999999999999;
	if (map->old_y <= 1)
		map->old_y = 0.99999999999-+9999;
	if (map->old_y > data->map_line - 0.999999999999999)
		map->old_y = data->map_line - 0.999999999999999;
	if (map->new_x <= 1)
		map->new_x = 0.999999999999999;
	if (map->new_x > data->col - 1)
		map->new_x = data->col - 1;
	if (map->new_y <= 1)
		map->new_y = 0.999999999999999;
	if (map->new_y >= data->map_line - 0.999999999999999)
		map->new_y = data->map_line - 0.999999999999999;
}

bool	must_exit_loop(t_map *map, t_data *data, char point)
{
	/* double	x;
	double	y;

	x = map->new_x;
	y = map->new_y; */
	if ((map->ya < 0 && map->new_y <= 1)
		|| (map->ya > 0 && map->new_y >= data->map_line - 1)
		|| (map->xa < 0 && map->new_x <= 1)//delete ?
		|| (map->xa > 0 && map->new_x >= data->col - 1))//delete ?
		return (true);
	else if (point == WALL
		|| point == '2')
		return (true);
	else
		return (false);
}

double	find_horizontal_wall_loop(t_data *data, t_map *map, double ray_angle)
{
	(void)ray_angle;
	map->new_x = map->old_x;
	map->new_y = map->old_y;
	printf("can_move: %d\n", can_move(data->map[(int)map->new_y][(int)map->new_x]));
	printf("map value: %d\n", data->map[(int)map->new_y][(int)map->new_x]);
	printf("new_x: %f, new_y: %f\n", map->new_x, map->new_y);
	while (can_move(data->map[(int)map->new_y][(int)map->new_x] == true))
	{
		if (must_exit_loop(map, data, data->map[(int)map->new_y][(int)map->new_x]) == true)
			break ;
		map->new_y = map->new_y + map->ya;
		//map->new_x = data->player_x + map->new_y * cos(ray_angle);
		map->new_x = (map->new_y - map->b) / map->m;
		adjust_extrem_value(map, data);
		printf("--> new_x: %f, new_y: %f, xa = %f, ya = %f\n", map->new_x, map->new_y, map->xa, map->ya);
		printf("\t(int)x = %d, (int)y = %d\n", (int)map->new_x, (int)map->new_y);
		map->len = sqrt(pow(map->new_x - data->player_x, 2) + pow(map->new_y - data->player_y, 2));
		//map->len = sqrt(pow(data->player_x - map->new_x, 2) + pow(data->player_y - map->new_y , 2));
	}
	printf("\033[1;33mlen = %f\n\033[0m", map->len);
	return (map->len);
}

double	find_horizontal_intersection(t_data *data, double ray_angle)
{
	t_map	map;

	get_slope_info(data, &map, ray_angle);
	if (sin(ray_angle) > 0)
	{
		printf("\033[31mFACING DOWN, sin(ray_angle) = %f\033[0m\n", sin(ray_angle));
		map.old_y = floor(data->player_y) + 1; //Here, we chose to make A part of the block above the line, that is why we subtract 1 from A.y
		map.ya = 1 + 0.000000000000001;
	}
	else
	{
		printf("\033[31mFACING UP, sin(ray_angle) = %f\033[0m\n", sin(ray_angle));
		map.old_y = floor(data->player_y);
		map.ya = -1 + 0.000000000000001;
	}
	map.old_x = (map.old_y - map.b) / map.m;
	printf ("ray_angle = %f, tan(ray_angle) = %f, YA = %f\n",ray_angle, tan(ray_angle), map.ya);
	adjust_extrem_value(&map, data);
	map.len = sqrt(pow(map.old_x - data->player_x, 2) + pow(map.old_y - data->player_y, 2));
	printf ("Xedge: old_x = %f\told_y = %f\tlen = %f\n", map.old_x, map.old_y, map.len);
	if (can_move(data->map[(int)map.old_y][(int)map.old_x]) == false)
		return (map.len);
	else
		return (find_horizontal_wall_loop(data, &map, ray_angle));
}

double	find_vertical_wall_loop(t_data *data, t_map *map, double ray_angle)
{
	(void)ray_angle;
	map->new_x = map->old_x;
	map->new_y = map->old_y;
	printf("can_move: %d\n", can_move(data->map[(int)map->new_y][(int)map->new_x]));
	printf("map value: %d\n", data->map[(int)map->new_y][(int)map->new_x]);
	printf("new_x: %f, new_y: %f\n", map->new_x, map->new_y);
	while (can_move(data->map[(int)map->new_y][(int)map->new_x] == true))
	{
		if (must_exit_loop(map, data, data->map[(int)map->new_y][(int)map->new_x]) == true)
			break ;
		map->new_x = map->new_x + map->xa;
		map->new_y = map->new_x * map->m + map->b;
		adjust_extrem_value(map, data);
		printf("--> new_x: %f, new_y: %f, xa = %f, ya = %f\n", map->new_x, map->new_y, map->xa, map->ya);
		printf("\t(int)x = %d, (int)y = %d\n", (int)map->new_x, (int)map->new_y);
		map->len = sqrt(pow(map->new_x - data->player_x, 2) + pow(map->new_y - data->player_y, 2));
	}
	printf("\033[1;33mlen = %f\n\033[0m", map->len);
	return (map->len);
}

double	find_vertical_intersection(t_data *data, double ray_angle)
{
	t_map	map;

	get_slope_info(data, &map, ray_angle);
	if (cos(ray_angle) <= 0)
	{
		printf("\033[32mFACING LEFT, cos(ray_angle) = %f\033[0m\n", cos(ray_angle));
		map.old_x = floor(data->player_x);
		map.xa = -1 - 0.0001;
	}
	else
	{
		printf("\033[32mFACING RIGHT, cos(ray_angle) = %f\033[0m\n", cos(ray_angle));
		map.old_x = floor(data->player_x) + 1;
		map.xa = 1 + 0.000000000000001;
	}
	map.old_y = map.old_x * map.m + map.b;
	adjust_extrem_value(&map, data);
	map.len = sqrt(pow(map.old_x - data->player_x, 2) + pow(map.old_y - data->player_y, 2));
	printf ("Yedge: old_x = %f\t, old_y = %f, lenb = %f, xa = %f, \n", map.old_x, map.old_y, map.len, map.xa);
	/* if (can_move(data->map[(int)map.old_y][(int)map.old_x]) == false)
		return (map.len);
	else */
		return (find_vertical_wall_loop(data, &map, ray_angle));
}
double	get_line_length_draft(t_data *data, double ray_angle)
{
	double	vertical_distance;
	double	horizontal_distance;
	double	len;

	//printf("angle = %f\n", ray_angle);
	/* if (ray_angle < 0)
		ray_angle = ray_angle + M_2_PI;//CONVERT NEGATIVE RADIAN TO POSITIVE */
	horizontal_distance = find_horizontal_intersection(data, ray_angle);
	vertical_distance = find_vertical_intersection(data, ray_angle);
	if (fabs(horizontal_distance) > fabs(vertical_distance))
		len = vertical_distance;
	else
		len = horizontal_distance;
	printf("\033[1;34mshortest len = %f\n\033[0m", len);
	printf("----------\n");
	return (len);
}
