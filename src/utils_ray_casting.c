/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:07:48 by blarger           #+#    #+#             */
/*   Updated: 2024/05/11 12:41:05 by blarger          ###   ########.fr       */
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
		map->old_y = 0.999999999999999;
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
static bool	is_wall(t_map *map, t_data *data, double ray_angle)
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

static bool	must_exit_loop(t_map *map, t_data *data, double ray_angle)
{
	double	x;
	double	y;

	x = map->new_x;
	y = map->new_y;
	if ((map->ya < 0 && map->new_y <= 1)
		|| (map->ya > 0 && map->new_y >= data->map_line - 1)
		|| (map->xa < 0 && map->new_x <= 1)
		|| (map->xa > 0 && map->new_x >= data->col - 1))
		return (true);
	/* else if (data->map[(int)y][(int)x] == WALL
		|| data->map[(int)y][(int)x] == '2')
		return (true); */
	else
		return (is_wall(map, data, ray_angle));
}

double	find_horizontal_wall_loop(t_data *data, t_map *map, double ray_angle)
{
	map->new_x = map->old_x;
	map->new_y = map->old_y;
	////printf("can_move: %d\n", can_move(data->map[(int)map->new_y][(int)map->new_x]));
	//printf("map value: %d\n", data->map[(int)map->new_y][(int)map->new_x]);
	//printf("new_x: %f, new_y: %f\n", map->new_x, map->new_y);
	while (must_exit_loop(map, data, ray_angle) == false)
	{

		map->new_y = map->new_y + map->ya;
		map->new_x = (map->new_y - map->b) / map->m;
		adjust_extrem_value(map, data);
		map->len = sqrt(pow(map->new_x - data->player_x, 2)
				+ pow(map->new_y - data->player_y, 2));

	}
	return (map->len);
}

double	find_vertical_wall_loop(t_data *data, t_map *map, double ray_angle)
{
	map->new_x = map->old_x;
	map->new_y = map->old_y;
	while (must_exit_loop(map, data, ray_angle) == false)
	{
		map->new_x = map->new_x + map->xa;
		map->new_y = map->new_x * map->m + map->b;
		adjust_extrem_value(map, data);
		map->len = sqrt(pow(map->new_x - data->player_x, 2)
				+ pow(map->new_y - data->player_y, 2));
	}
	return (map->len);
}
