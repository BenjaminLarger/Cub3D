/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 18:10:56 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calculate_col_height(t_pfv *pfv)
{
	pfv->calculated_h = WIDTH / pfv->ray_length;
	if (pfv->calculated_h > HEIGHT)
		pfv->display_h = HEIGHT;
	else
		pfv->display_h = pfv->calculated_h;
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
		wall_color = get_col_px_colour((h - col_start_y) / pfv.calculated_h,
				data, pfv);
		mlx_put_pixel(data->world, pfv.i, h, wall_color);
		h++;
	}
	while (h < HEIGHT)
		mlx_put_pixel(data->world, pfv.i, h++, data->floor_color);
}

static void	check_anomalies(t_data *data, t_pfv *pfv)
{
	double	diff1;
	double	diff2;
	double	threshold1;
	double	threshold2;

	diff1 = fabs(pfv->ray_length_n2 - pfv->ray_length_n1);
	diff2 = fabs(pfv->ray_length_n1 - pfv->ray_length);
	threshold1 = 0.1 * pfv->ray_length_n2;
	threshold2 = 0.1 * pfv->ray_length_n1;
	if (pfv->i != 0 && diff1 > threshold1 && diff2 > threshold2)
	{
		pfv->i--;
		paint_column(data, pfv->display_h,
			(HEIGHT / 2) - (pfv->calculated_h / 2), *pfv);
		pfv->i++;
	}
}

static void	update_prev_rays_distance_data(t_pfv *pfv)
{
	if (pfv->i == 0)
		pfv->ray_length_n1 = pfv->ray_length;
	pfv->ray_length_n2 = pfv->ray_length_n1;
	pfv->ray_length_n1 = pfv->ray_length;
}

void	paint_walls(t_data *data)
{
	t_pfv	pfv;

	pfv.i = 0;
	while (pfv.i < NUM_OF_RAYS)
	{
		pfv.ray_angle = data->player_angle
			- (data->view_angle / 2) + pfv.i * data->angle_step;
		update_prev_rays_distance_data(&pfv);
		pfv.ray_length = get_wall_distance(data, pfv.ray_angle);
		pfv.wall_x_n1 = pfv.wall_x;
		pfv.wall_y_n1 = pfv.wall_y;
		pfv.wall_x = data->player_x + cos(pfv.ray_angle) * pfv.ray_length;
		pfv.wall_y = data->player_y + sin(pfv.ray_angle) * pfv.ray_length;
		pfv.ray_length *= cos(pfv.ray_angle - data->player_angle);
		calculate_col_height(&pfv);
		if (pfv.i < WIDTH)
			paint_column(data, pfv.display_h,
				(HEIGHT / 2) - (pfv.calculated_h / 2), pfv);
		check_anomalies(data, &pfv);
		pfv.i++;
	}
}
