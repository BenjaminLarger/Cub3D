/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:54:02 by demre             #+#    #+#             */
/*   Updated: 2024/04/24 19:21:40 by demre            ###   ########.fr       */
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

static double	get_line_length(t_data *data)
{
	double	distance_to_wall = 0;
	double	ray_x = data->player_x;
	double	ray_y = data->player_y;
	double	ray_dx = cos(data->player_angle);
	double	ray_dy = sin(data->player_angle);
	printf("int ray_dx = %d, ray_dy = %d\n", (int)ray_dx, (int)ray_dy);
	printf("double ray_dx = %f, ray_dy = %f\n", ray_dx, ray_dy);
	while (1)
	{
		distance_to_wall += 1;
		ray_x += ray_dx;
		ray_y += ray_dy;
		if (data->map[(int)ray_y][(int)ray_x] == WALL)
			break;
	}
	return (distance_to_wall);
}

static void	paint_field_of_view(t_data *data)
{
	double ray_length = get_line_length(data);
	printf("ray_length = %f\n", ray_length);
	double endX = ray_length * cos(data->player_angle);
	double endY = ray_length * sin(data->player_angle);

	printf("Player position: (%.2f, %.2f), angle: %.2f\n", data->player_x, data->player_y, data->player_angle);
	printf("Ray length (X,Y): (%.2f, %.2f)\n", endX, endY);
	int n_pixels_to_draw = sqrt((endX * endX) + (endY * endY))
		* data->minimap_tile_px;
	int total_pixels_to_draw = n_pixels_to_draw;
	printf("minimap_tile_px: (%u), n_pixels: (%d), endX: %f, endY: %f\n", data->minimap_tile_px, n_pixels_to_draw, endX, endY);

	double pixelX = (data->player_x * data->minimap_tile_px)
		+ (data->minimap_tile_px / 2);
	double pixelY = (data->player_y * data->minimap_tile_px)
		+ (data->minimap_tile_px / 2);
	while (n_pixels_to_draw)
	{
//		printf("n_pixels: %d, pixelX: %f, pixelY: %f, data->player_angle: %f\n", n_pixels_to_draw, pixelX, pixelY, data->player_angle);
		mlx_put_pixel(data->minimap, pixelX, pixelY, 0xffaa00AA);
		pixelX += endX * data->minimap_tile_px / total_pixels_to_draw;
		pixelY += endY * data->minimap_tile_px / total_pixels_to_draw;
		--n_pixels_to_draw;
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
