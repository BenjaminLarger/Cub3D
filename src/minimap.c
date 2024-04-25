/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:54:02 by demre             #+#    #+#             */
/*   Updated: 2024/04/25 10:16:23 by blarger          ###   ########.fr       */
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
	printf("data->player_x: %f, data->player_y: %f\n", data->player_x, data->player_y);
	paint_one_tile(data, 0xff0000AA, data->player_x, data->player_y);
}

static double	get_line_length(t_data *data, double ray_angle)
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
		if (data->map[(int)ray_y][(int)ray_x] == WALL)
			break ;
	}
	return (distance_to_wall);
}

static void	paint_field_of_view(t_data *data)
{
	double	ray_length;
	double	endX;
	double 	endY;
	int		n_pixels_to_draw;
	int 	total_pixels_to_draw;
	double 	pixelX;
	double 	pixelY;
	double 	view_angle = PLAYER_FOV * (M_PI / 180);
	double 	angle_step = view_angle / NUM_OF_RAYS; //200 = nmumber of rays
	double 	ray_angle;

	for (int i = 0; i < NUM_OF_RAYS; i++)
	{
		ray_angle = data->player_angle - (view_angle / 2) + i * angle_step;
		ray_length = get_line_length(data, ray_angle);
		endX = ray_length * cos(ray_angle);
		endY = ray_length * sin(ray_angle);
		n_pixels_to_draw = sqrt((endX * endX) + (endY * endY))
			* data->minimap_tile_px;
		total_pixels_to_draw = n_pixels_to_draw;
		pixelX = (data->player_x * data->minimap_tile_px);
		pixelY = (data->player_y * data->minimap_tile_px);
		while (n_pixels_to_draw)
		{
			mlx_put_pixel(data->minimap, pixelX, pixelY, 0xffaa00AA);
			pixelX += endX * data->minimap_tile_px / total_pixels_to_draw;
			pixelY += endY * data->minimap_tile_px / total_pixels_to_draw;
			--n_pixels_to_draw;
		}
	}
}

void	paint_minimap(t_data *data)
{
	unsigned int	row;

	row = 0;
	data->minimap = mlx_new_image(data->mlx,
		data->col * data->minimap_tile_px, data->row * data->minimap_tile_px);
	mlx_image_to_window(data->mlx, data->minimap, 32, 32);
	while (data->map[row])
	{
		paint_line(data->map[row], data, row);
		row++;
	}
	paint_player(data);
	paint_field_of_view(data);
}
