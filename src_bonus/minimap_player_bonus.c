/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:41:22 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 18:28:16 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_line(t_data *data, t_mm_plyr plyr)
{
	int		k;
	double	x;
	double	y;

	x = plyr.center_x;
	y = plyr.center_y;
	if (fabs(plyr.dx) > fabs(plyr.dy))
		plyr.steps = fabs(plyr.dx);
	else
		plyr.steps = fabs(plyr.dy);
	plyr.x_inc = plyr.dx / (double)plyr.steps;
	plyr.y_inc = plyr.dy / (double)plyr.steps;
	k = 0;
	while (k < plyr.steps)
	{
		mlx_put_pixel(data->minimap, x, y, 0xffaa00AA);
		x += plyr.x_inc;
		y += plyr.y_inc;
		k++;
	}
}

void	draw_cone(t_data *data, t_mm_plyr plyr)
{
	double	cone_angle;
	double	end_angle;

	cone_angle = data->player_angle - 0.12 * M_PI;
	end_angle = data->player_angle + 0.12 * M_PI;
	while (cone_angle < end_angle)
	{
		plyr.dx = plyr.radius * cos(cone_angle);
		plyr.dy = plyr.radius * sin(cone_angle);
		draw_line(data, plyr);
		cone_angle += 0.01 * M_PI;
	}
}

void	paint_mm_player(t_data *data)
{
	t_mm_plyr	plyr;

	plyr.center_x = (data->player_x - data->mm_col_start_px)
		* data->minimap_tile_px;
	plyr.center_y = (data->player_y - data->mm_row_start_px)
		* data->minimap_tile_px;
	plyr.radius = data->minimap_tile_px / 4;
	plyr.x = plyr.center_x - plyr.radius;
	while (plyr.x <= plyr.center_x + plyr.radius)
	{
		plyr.y = plyr.center_y - plyr.radius;
		while (plyr.y <= plyr.center_y + plyr.radius)
		{
			if ((plyr.x - plyr.center_x) * (plyr.x - plyr.center_x)
				+ (plyr.y - plyr.center_y) * (plyr.y - plyr.center_y)
				<= plyr.radius * plyr.radius)
				mlx_put_pixel(data->minimap, plyr.x, plyr.y, 0xff0000AA);
			plyr.y++;
		}
		plyr.x++;
	}
	draw_cone(data, plyr);
}
