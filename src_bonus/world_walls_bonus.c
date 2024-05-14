/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/05/14 14:27:06 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		if (pfv.obstacle == 'C')
			wall_color = get_col_px_colour_door((h - col_start_y)
						/ data->calculated_h, data, pfv, data->door_close);
		else if (pfv.obstacle == 'O')
			wall_color = get_col_px_colour_door((h - col_start_y)
						/ data->calculated_h, data, pfv, data->door_open);
		else
			wall_color = get_col_px_colour((h - col_start_y)
						/ data->calculated_h, data, pfv);
		mlx_put_pixel(data->world, pfv.i, h, wall_color);
		h++;
	}
	while (h < HEIGHT)
		mlx_put_pixel(data->world, pfv.i, h++, data->floor_color);
}

static void	get_obstacle_type_on_right_side(t_data *data, t_pfv *pfv)
{ // Bottom-right horz, Bottom-right vert, Top-right horz, Top-right vert
	if (sin(pfv->ray_angle) > 0
		&& fabs(pfv->wall_y - round(pfv->wall_y)) < 0.00001)
	{
		pfv->obs_x = (int)(pfv->wall_x);
		pfv->obs_y = (int)(pfv->wall_y + 0.2);
	}
	else if (sin(pfv->ray_angle) > 0)
	{
		pfv->obs_x = (int)(pfv->wall_x + 0.2);
		pfv->obs_y = (int)(pfv->wall_y);
	}
	else if (sin(pfv->ray_angle) <= 0
		&& fabs(pfv->wall_y - round(pfv->wall_y)) < 0.00001)
	{
		pfv->obs_x = (int)(pfv->wall_x);
		pfv->obs_y = (int)(pfv->wall_y - 0.2);
	}
	else
	{
		pfv->obs_x = (int)(pfv->wall_x + 0.2);
		pfv->obs_y = (int)(pfv->wall_y);
	}
	pfv->obstacle = data->map[pfv->obs_y][pfv->obs_x];
}

static void	get_obstacle_type_on_left_side(t_data *data, t_pfv *pfv)
{ // Bottom-left horz, Bottom-left vert, Top-left horz, Top-left vert
	if (sin(pfv->ray_angle) > 0
		&& fabs(pfv->wall_y - round(pfv->wall_y)) < 0.00001)
	{
		pfv->obs_x = (int)(pfv->wall_x);
		pfv->obs_y = (int)(pfv->wall_y + 0.2);
	}
	else if (sin(pfv->ray_angle) > 0)
	{
		pfv->obs_x = (int)(pfv->wall_x - 0.2);
		pfv->obs_y = (int)(pfv->wall_y);
	}
	else if (sin(pfv->ray_angle) <= 0
		&& fabs(pfv->wall_y - round(pfv->wall_y)) < 0.00001)
	{
		pfv->obs_x = (int)(pfv->wall_x);
		pfv->obs_y = (int)(pfv->wall_y - 0.2);
	}
	else
	{
		pfv->obs_x = (int)(pfv->wall_x - 0.2);
		pfv->obs_y = (int)(pfv->wall_y);
	}
	pfv->obstacle = data->map[pfv->obs_y][pfv->obs_x];
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
		if (cos(pfv.ray_angle) > 0)
			get_obstacle_type_on_right_side(data, &pfv);
		else
			get_obstacle_type_on_left_side(data, &pfv);
		pfv.ray_length *= cos(pfv.ray_angle - data->player_angle);
		calculate_col_height(data, pfv);
//		if (pfv.i % 16 == 0)
//				printf("%d, wall_x,y: %f:%f, obstacle: %c, distance: %f\n", pfv.i, pfv.wall_x, pfv.wall_y, pfv.obstacle, pfv.ray_length);

		if (pfv.i < WIDTH)
			paint_column(data, data->display_h,
				(HEIGHT / 2) - (data->calculated_h / 2), pfv);
		pfv.i++;
	}
}
