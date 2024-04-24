/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:54:02 by demre             #+#    #+#             */
/*   Updated: 2024/04/24 18:03:27 by demre            ###   ########.fr       */
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
		if (line[col] == '1')
			paint_one_tile(data, 0xaaaaaa99, col, row);
		else if (line[col] != ' ')
			paint_one_tile(data, 0x11111199, col, row);
		col++;
	}
}

static void	paint_player(t_data *data)
{
	printf("data->player_x: %f, data->player_y: %f\n", data->player_x, data->player_y);
	paint_one_tile(data, 0xff0000AA, data->player_x, data->player_y);
}

static void	paint_field_of_view(t_data *data)
{
	double line_length = 10;
	double endX = data->player_x + line_length * cos(data->player_angle);
	double endY = data->player_y + line_length * sin(data->player_angle);

	printf("Player position: (%.2f, %.2f), angle: %.2f\n", data->player_x, data->player_y, data->player_angle);
	printf("Line endpoint: (%.2f, %.2f)\n", endX, endY);
	double deltaX = endX - data->player_x;
	double deltaY = endY - data->player_y;
	int n_pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY))
		* data->minimap_tile_px;

	double pixelX = (data->player_x * data->minimap_tile_px)
		+ (data->minimap_tile_px / 2);
	double pixelY = (data->player_y * data->minimap_tile_px)
		+ (data->minimap_tile_px / 2);
	while (n_pixels)
	{
//		printf("n_pixels: %d, pixelX: %f, pixelY: %f, data->player_angle: %f\n", n_pixels, pixelX, pixelY, data->player_angle);
		mlx_put_pixel(data->minimap, pixelX, pixelY, 0xffaa00AA);
		pixelX += (deltaX / data->minimap_tile_px);
		pixelY += (deltaY / data->minimap_tile_px);
		--n_pixels;
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
