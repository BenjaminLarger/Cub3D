/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/30 17:52:04 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_col_height(t_data *data, t_pfv pfv)
{
	data->calculated_h = WIDTH * 1170 / pfv.ray_length / HEIGHT;
	if (data->calculated_h > HEIGHT)
		data->display_h = HEIGHT;
	else
		data->display_h = data->calculated_h;
}

/* static double	get_intersection_length_loop(t_data *data, t_edge *edge,
	t_pfv *pfv, double accuracy)
{
	bool	can_continue;

	if (accuracy < 0)
		can_continue = false;
	else
		can_continue = true;
	edge->ray_dx = cos(edge->ray_angle) * accuracy;
	edge->ray_dy = sin(edge->ray_angle) * accuracy;
	while (can_move(data->map[(int)pfv->wall_y][(int)pfv->wall_x])
		== can_continue)
	{
		edge->distance_to_wall += accuracy;
		pfv->wall_x += edge->ray_dx;
		pfv->wall_y += edge->ray_dy;
	}
	return (edge->distance_to_wall);
}

double	get_intersection(t_data *data, double ray_angle,
	t_pfv *pfv)
{
	t_edge	edge;
	double	accuracy;
	int		i;

	edge.ray_angle = ray_angle;
	edge.distance_to_wall = 0;
	pfv->wall_x = data->player_x;
	pfv->wall_y = data->player_y;
	accuracy = -1;
	i = 0;
	while (i < 2)
	{
		accuracy /= -10;
		edge.distance_to_wall = get_intersection_length_loop(data, &edge, pfv, accuracy);
		i++;
	}
	edge.distance_to_wall *= cos(ray_angle - data->player_angle);
//	edge.distance_to_wall = round(edge.distance_to_wall * 100) / 100;
	return (edge.distance_to_wall);
} */

double	get_intersection(t_data *data, double ray_angle,
	double *wall_x, double *wall_y)
{
	double	distance_to_wall;
	double	ray_dx;
	double	ray_dy;

	distance_to_wall = 0;
	*wall_x = data->player_x;
	*wall_y = data->player_y;
	ray_dx = cos(ray_angle) * 0.01;
	ray_dy = sin(ray_angle) * 0.01;
	while (1)
	{
		distance_to_wall += 0.01;
		*wall_x += ray_dx;
		*wall_y += ray_dy;
		if (can_move(data->map[(int)(*wall_y)][(int)(*wall_x)]) == false)
			break ;
	}
	distance_to_wall *= cos(ray_angle - data->player_angle);
	distance_to_wall = round(distance_to_wall * 100) / 100; //
	return (distance_to_wall);
}
