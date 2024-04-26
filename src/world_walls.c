/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/04/26 17:17:02 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	get_intersection(t_data *data, double ray_angle,
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
//	printf("wall_x: %f, wall_y: %f\n", *wall_x, *wall_y);
	while (1)
	{
		distance_to_wall += 0.01;
		*wall_x += ray_dx;
		*wall_y += ray_dy;
		if (can_move(data->map[(int)(*wall_y)][(int)(*wall_x)]) == false)
			break ;
	}
//	printf("wall_x: %f, wall_y: %f, distance_to_wall: %f\n", *wall_x, *wall_y, distance_to_wall);
	return (distance_to_wall);
}

static void	paint_column(t_data *data, double h, double calculated_h, t_pfv	pfv)
{
	int	x;

	x = 0;
	while (x < 10)
	{
		if ((x + WIDTH * pfv.i / NUM_OF_RAYS) < WIDTH)
			mlx_put_pixel(data->world, x + WIDTH * pfv.i / NUM_OF_RAYS, (HEIGHT / 2) - (calculated_h / 2) + h, 0xffaa00AA);
		x++;
	}
}

void	paint_walls(t_data *data)
{
	t_pfv	pfv;
	double	wall_x; // not used
	double	wall_y; // not used
	double	calculated_h;
	double	h;

	pfv.i = 0;
	pfv.view_angle = PLAYER_FOV * (M_PI / 180);
	pfv.angle_step = pfv.view_angle / NUM_OF_RAYS;
	while (pfv.i < NUM_OF_RAYS + 1)
	{
		pfv.ray_angle = data->player_angle
			- (pfv.view_angle / 2) + pfv.i * pfv.angle_step;
		pfv.ray_length = get_intersection(data, pfv.ray_angle, &wall_x,
			&wall_y);
//		printf("wall at wall_x: %f, wall_y: %f\n", wall_x, wall_y);
		calculated_h = calculate_col_height(data, pfv);
		if (calculated_h > HEIGHT)
			calculated_h = HEIGHT;
//		printf("WIDTH * pfv.i / NUM_OF_RAYS: %d, calculated_h: %f\n",
//			WIDTH * pfv.i / NUM_OF_RAYS, calculated_h);
//		printf("(HEIGHT / 2) - (calculated_h / 2) - h: %f\n",
//			(HEIGHT / 2) - (calculated_h / 2) + 0);
		h = 0;
		while (h < calculated_h)
		{
			paint_column(data, h, calculated_h, pfv);
			h++;
		}
		pfv.i++;
	}
}
