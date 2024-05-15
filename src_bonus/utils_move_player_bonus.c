/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_move_player_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 10:42:18 by blarger           #+#    #+#             */
/*   Updated: 2024/05/15 21:08:21 by blarger          ###   ########.fr       */
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
	{
		data->move_in_corner = true;
		return (false);
	}
	if (data->map[(int)y][(int)x] == WALL || data->map[(int)y][(int)x] == '2'
		|| data->map[(int)y][(int)x] == DOOR_CLOSED)
		return (false);
	else
		return (true);
}

int	get_next_wall(t_data *data, double angle)
{
	double	vertical_wall_dist;
	double	horizontal_wall_dist;

	vertical_wall_dist = find_vertical_intersection(data, angle);
	horizontal_wall_dist = find_horizontal_intersection(data, angle);
	printf("x = %f, y = %f\n", data->player_x, data->player_y);
	printf("vert dist = %f, hor dist = %f\n", vertical_wall_dist, horizontal_wall_dist);
	if (vertical_wall_dist < 0.3 && horizontal_wall_dist < 0.3)
		return (-1);
	else if (vertical_wall_dist > horizontal_wall_dist)
	{
		return (HW);
	}
	else
	{
		return (VW);
	}
}

void	player_slide_on_wall(t_data *data, char *direction,
	double end_x, double end_y)
{
	double	angle;

	if (!ft_strcmp(direction, FORWARD))
		angle = data->player_angle;
	else
	{
		end_x *= -1;
		end_y *= -1;
		angle = data->player_angle - M_PI;
	}
	if (angle < 0)
		angle += 2 * M_PI;
	if (get_next_wall(data, angle) == HW && end_x > 0 && move_in_corner(data, 0.1, 0) == false)
		data->player_x += 0.1;
	else if (get_next_wall(data, angle) == HW && end_x < 0 && move_in_corner(data, -0.1, 0) == false)
		data->player_x -= 0.1;
	else if (get_next_wall(data, angle) == VW && end_y > 0 && move_in_corner(data, 0, 0.1) == false)
		data->player_y += 0.1;
	else if (get_next_wall(data, angle) == VW && end_y < 0 && move_in_corner(data, 0, -0.1) == false)
		data->player_y -= 0.1;
}
