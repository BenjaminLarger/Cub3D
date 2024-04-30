/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/30 15:04:51 by demre            ###   ########.fr       */
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
