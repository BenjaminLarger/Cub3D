/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 13:51:34 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		if (pfv.obstacle == 'C')
			wall_color = get_col_px_colour_door((h - col_start_y)
					/ data->calculated_h, data, pfv, data->door_close);
		else
			wall_color = get_col_px_colour((h - col_start_y)
						/ data->calculated_h, data, pfv);
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
		pfv.wall_x = data->player_x + cos(pfv.ray_angle) * pfv.ray_length;
		pfv.wall_y = data->player_y + sin(pfv.ray_angle) * pfv.ray_length;
		if (cos(pfv.ray_angle) > 0)
			get_obstacle_type_on_right_side(data, &pfv);
		else
			get_obstacle_type_on_left_side(data, &pfv);
		pfv.ray_length *= cos(pfv.ray_angle - data->player_angle);
		calculate_col_height(data, pfv);
		//if (pfv.i % 16 == 0)
		//		printf("%d, wall_x,y: %f:%f, obstacle: %c, distance: %f\n", pfv.i, pfv.wall_x, pfv.wall_y, pfv.obstacle, pfv.ray_length);
		check_player_can_open_door(data, pfv);
		if (pfv.i < WIDTH)
			paint_column(data, data->display_h,
				(HEIGHT / 2) - (data->calculated_h / 2), pfv);
		pfv.i++;
	}
}


