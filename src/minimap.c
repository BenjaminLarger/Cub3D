/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:54:02 by demre             #+#    #+#             */
/*   Updated: 2024/04/25 14:15:22 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	paint_one_tile(t_data *data, int colour, unsigned int col,
	unsigned int row)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < data->minimap_tile_px)
	{
		y = 0;
		while (y < data->minimap_tile_px)
		{
			mlx_put_pixel(data->minimap, col * data->minimap_tile_px + x,
				row * data->minimap_tile_px + y, colour);
			y++;
		}
		x++;
	}
}

static void	paint_line(char *line, t_data *data, unsigned int row)
{
	unsigned int	col;

	col = 0;
	while (line[col])
	{
		if (line[col] == WALL)
			paint_one_tile(data, 0xaaaaaa99, col, row);
		else if (line[col] != OUT)
			paint_one_tile(data, 0x11111199, col, row);
		col++;
	}
}

static void	paint_player(t_data *data)
{
	//printf("data->player_x: %f, data->player_y: %f\n", data->player_x, data->player_y);
	paint_one_tile(data, 0xff0000AA, data->player_x, data->player_y);
}


static double	get_line_length(t_data *data, double ray_angle, int ray_index)
{
	double	distance_to_wall;
	double	ray_x;
	double	ray_y;
	double	ray_dx;
	double	ray_dy;

	distance_to_wall = 0;
	ray_x = data->player_x;
	ray_y = data->player_y;
	ray_dx = cos(ray_angle) * 0.01;
	ray_dy = sin(ray_angle) * 0.01;
	while (1)
	{
		distance_to_wall += 0.01;
		ray_x += ray_dx;
		ray_y += ray_dy;
		if (access_denied(data->map[(int)ray_y][(int)ray_x]) == true)
			break ;
	}
	draw_ground(data, ray_index, distance_to_wall);
	return (distance_to_wall);
}

static void	paint_field_of_view(t_data *data)
{
	t_pfv 	pfv;

	pfv.i = 0;
	pfv.view_angle = PLAYER_FOV * (M_PI / 180);
	pfv.angle_step = pfv.view_angle / NUM_OF_RAYS; //200 = nmumber of rays
	while (pfv.i < NUM_OF_RAYS)
	{
		pfv.ray_angle = data->player_angle
			- (pfv.view_angle / 2) + pfv.i * pfv.angle_step;
		pfv.ray_length = get_line_length(data, pfv.ray_angle, pfv.i);
		pfv.endX = pfv.ray_length * cos(pfv.ray_angle);
		pfv.endY = pfv.ray_length * sin(pfv.ray_angle);
		pfv.n_pixels_to_draw = sqrt((pfv.endX * pfv.endX) + (pfv.endY * pfv.endY)) * data->minimap_tile_px;
		pfv.total_pixels_to_draw = pfv.n_pixels_to_draw;
		pfv.pixelX = (data->player_x * data->minimap_tile_px);
		pfv.pixelY = (data->player_y * data->minimap_tile_px);
		while (pfv.n_pixels_to_draw)
		{
			mlx_put_pixel(data->minimap, pfv.pixelX, pfv.pixelY, 0xffaa00AA);
			pfv.pixelX += pfv.endX * data->minimap_tile_px / pfv.total_pixels_to_draw;
			pfv.pixelY += pfv.endY * data->minimap_tile_px / pfv.total_pixels_to_draw;
			--pfv.n_pixels_to_draw;
		}
		pfv.i++;
	}
}

void	paint_minimap(t_data *data)
{
	unsigned int	row;

	row = 0;
	while (data->map[row])
	{
		paint_line(data->map[row], data, row);
		row++;
	}
	paint_player(data);
	paint_field_of_view(data);
}
