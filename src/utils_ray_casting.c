/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray_casting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:07:48 by blarger           #+#    #+#             */
/*   Updated: 2024/04/30 17:34:53 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_line_length_loop(t_data *data, t_edge *edge,
	double accuracy)
{
	bool	can_continue;

	if (accuracy < 0)
		can_continue = false;
	else
		can_continue = true;
	edge->ray_dx = cos(edge->ray_angle) * accuracy;
	edge->ray_dy = sin(edge->ray_angle) * accuracy;
	while (can_move(data->map[(int)edge->ray_y][(int)edge->ray_x])
		== can_continue)
	{
		edge->distance_to_wall += accuracy;
		edge->ray_x += edge->ray_dx;
		edge->ray_y += edge->ray_dy;
	}
	return (edge->distance_to_wall);
}

double	get_line_length(t_data *data, double ray_angle)
{
	t_edge	edge;
	double	accuracy;
	int		i;

	edge.ray_angle = ray_angle;
	edge.distance_to_wall = 0;
	edge.ray_x = data->player_x;
	edge.ray_y = data->player_y;
	accuracy = -8;
	i = 0;
	while (i < 2)
	{
		accuracy /= -10;
		edge.distance_to_wall = get_line_length_loop(data, &edge, accuracy);
		i++;
	}
	return (edge.distance_to_wall);
}

t_edge	world_to_grid(double x, double y)
{
	t_edge	grid;

	grid.x = floor(x);
	grid.y = floor(y);
	return (grid);
}
t_edge	find_intersection(t_edge *edge)
{
	t_edge	a;
	double	tan_alpha;

	tan_alpha = tan(edge->ray_angle);
	if (edge->ray_angle > M_PI_2 && edge->ray_angle < 3 * M_PI_2)
		a.y = floor(edge->cur_y) - 1;
	else
		a.y = floor(edge->cur_y) + 1;
	a.x = edge->cur_x + (edge->cur_x - a.y) / tan_alpha;
	a = world_to_grid(a.x, a.y);
	return (a);
}

t_edge	find_point_c(t_edge a)
{
	t_edge	c;
	double	xa;
	double	ya;

	xa = 1 / tan(M_PI / 3);
}

static double	get_line_length(t_data *data, double ray_angle)
{
	t_edge	edge;
	t_edge	a;
	t_edge	c;

	edge.cur_x = data->player_x;
	edge.cur_y = data->player_y;
	edge.ray_angle = ray_angle;
	a = find_intersection(&edge);
	c = find_point_c(a);
}
