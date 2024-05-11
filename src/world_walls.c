/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/05/11 13:44:30 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	paint_column(t_data *data, double display_h,
	double col_start_y, t_pfv pfv)
{
	double			h;
	double			adjusted_col_start_y;
	unsigned int	colour;
	unsigned int	screen_x;

//printf("%f, %f\n", display_h, col_start_y);
	screen_x = WIDTH * pfv.i / NUM_OF_RAYS;
	if (col_start_y < 0)
		adjusted_col_start_y = 0;
	else
		adjusted_col_start_y = col_start_y;
	h = 0;
	while (h < adjusted_col_start_y)
		if (screen_x < WIDTH)
			mlx_put_pixel(data->world, screen_x, h++, data->sky_color);
	while (h < adjusted_col_start_y + display_h)
	{
		if (screen_x < WIDTH)
		{
			colour = get_col_px_colour(
				100 * (h - col_start_y) / data->calculated_h,
				data, pfv);
			mlx_put_pixel(data->world, screen_x, h, colour);
		}
		h++;
	}
	while (h < HEIGHT)
		if (screen_x < WIDTH)
			mlx_put_pixel(data->world, screen_x, h++, data->floor_color);
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
		pfv.wall_x = data->player_x +  cos(pfv.ray_angle) * pfv.ray_length;
		pfv.wall_y = data->player_y + sin(pfv.ray_angle) * pfv.ray_length;
		pfv.ray_length *= cos(pfv.ray_angle - data->player_angle);
		//pfv.ray_length = get_intersection(data, pfv.ray_angle, &pfv.wall_x, &pfv.wall_y);
		calculate_col_height(data, pfv);

//	unsigned int colour = get_col_px_colour(WIDTH * pfv.i / NUM_OF_RAYS, display_h, data, pfv); //
//	printf("%d, wall_x:y: %f:%f, player_x:y: %f:%f, distance_to_wall: %.2f, colour: %u\n", pfv.i, pfv.wall_x, pfv.wall_y, data->player_x, data->player_y, pfv.ray_length, colour);
//	printf("pfv.wall_x - data->player_x: %.3f, (pfv.wall_x - round(pfv.wall_x): %.3f, pfv.wall_y - data->player_y: %.3f, (pfv.wall_y - round(pfv.wall_y)): %.3f\n", pfv.wall_x - data->player_x, (pfv.wall_x - round(pfv.wall_x)), pfv.wall_y - data->player_y, (pfv.wall_y - round(pfv.wall_y)));
//	printf("wall_x:y: %f:%f\n", 400 * (pfv.wall_x - (int)pfv.wall_x), 300 * (pfv.wall_y - (int)pfv.wall_y));
	
	//	printf("WIDTH * %d / NUM_OF_RAYS: %d, display_h: %f\n",
	//		pfv.i, WIDTH * pfv.i / NUM_OF_RAYS, display_h);
	//	printf("(HEIGHT / 2) - (display_h / 2) - h: %f\n",
	//		(HEIGHT / 2) - (display_h / 2) + 0);

		paint_column(data, data->display_h,
			(HEIGHT / 2) - (data->calculated_h / 2), pfv);
		pfv.i++;
	}
}
