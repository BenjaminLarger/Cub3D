/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/05/14 12:09:50 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_col_height(t_data *data, t_pfv pfv)
{
	data->calculated_h = WIDTH / pfv.ray_length;
	if (data->calculated_h > HEIGHT)
		data->display_h = HEIGHT;
	else
		data->display_h = data->calculated_h;
}

static void	paint_column(t_data *data, double display_h,
	double col_start_y, t_pfv pfv)
{
	double		h;
	double		adjusted_col_start_y;
	uint32_t	wall_color;

	if (col_start_y < 0)
		adjusted_col_start_y = 0;
	else
		adjusted_col_start_y = col_start_y;
	h = 0;
	while (h < adjusted_col_start_y)
		mlx_put_pixel(data->world, pfv.i, h++, data->sky_color);
	while (h < adjusted_col_start_y + display_h)
	{
		wall_color = get_col_px_colour((h - col_start_y) / data->calculated_h,
				data, pfv);
		mlx_put_pixel(data->world, pfv.i, h, wall_color);
		h++;
	}
	while (h < HEIGHT)
		mlx_put_pixel(data->world, pfv.i, h++, data->floor_color);
}

void	paint_walls(t_data *data)
{
	t_pfv	pfv;

	pfv.i = 0;
	while (pfv.i < NUM_OF_RAYS)
	{
		pfv.ray_angle = data->player_angle
			- (data->view_angle / 2) + pfv.i * data->angle_step;
		pfv.ray_length = get_wall_distance(data, pfv.ray_angle);
		pfv.prev_wall_x = pfv.wall_x;
		pfv.prev_wall_y = pfv.wall_y;
		pfv.wall_x = data->player_x + cos(pfv.ray_angle) * pfv.ray_length;
		pfv.wall_y = data->player_y + sin(pfv.ray_angle) * pfv.ray_length;
		pfv.ray_length *= cos(pfv.ray_angle - data->player_angle);
		calculate_col_height(data, pfv);
		if (pfv.i < WIDTH)
			paint_column(data, data->display_h,
				(HEIGHT / 2) - (data->calculated_h / 2), pfv);
		pfv.i++;
	}
}
