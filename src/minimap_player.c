/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:41:22 by demre             #+#    #+#             */
/*   Updated: 2024/05/12 15:52:02 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/* 
void	paint_mm_player(t_data *data) // draw square player
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	pos_x;
	unsigned int	pos_y;

//			pos_x = (data->player_x - 0.5 - data->mm_col_start_px) * data->minimap_tile_px + 4; // delete
//			pos_y = (data->player_y - 0.5 - data->mm_row_start_px) * data->minimap_tile_px + 4; // delete
//			printf("data->player_x,y: %.2f,%.2f pos_x,y: %u,%u\n", data->player_x, data->player_y, pos_x, pos_y);
	x = data->minimap_tile_px / 4;
	while (x < data->minimap_tile_px - data->minimap_tile_px / 4)
	{
		y = data->minimap_tile_px / 4;
		while (y < data->minimap_tile_px - data->minimap_tile_px / 4)
		{
			pos_x = (data->player_x - 0.5 - data->mm_col_start_px)
				* data->minimap_tile_px + x;
			pos_y = (data->player_y - 0.5 - data->mm_row_start_px)
				* data->minimap_tile_px + y;
			mlx_put_pixel(data->minimap, pos_x, pos_y, 0xff0000AA);
			y++;
		}
		x++;
	}
//	printf("data->player_x,y: %.2f,%.2f pos_x,y: %u,%u\n", data->player_x, data->player_y, pos_x, pos_y); //
}
 */

void draw_vision_line(t_data *data, int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx, sy;

	if (x0 < x1)
		sx = 1;
	else
		sx = -1;

	if (y0 < y1)
		sy = 1;
	else
		sy = -1;

	int err = (dx > dy ? dx : -dy) / 2;
	int e2;

	while (1)
	{
		mlx_put_pixel(data->minimap, x0, y0, 0xffaa00AA);
		if (x0 == x1 && y0 == y1)
			break;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}


void	paint_mm_player(t_data *data)
{
	unsigned int center_x = (data->player_x - data->mm_col_start_px) * data->minimap_tile_px;
	unsigned int center_y = (data->player_y - data->mm_row_start_px) * data->minimap_tile_px;
	double radius = data->minimap_tile_px / 4;

	// Calculate endpoint of the line
	double line_end_x = center_x + radius * cos(data->player_angle);
	double line_end_y = center_y + radius * sin(data->player_angle);

	for (int x = center_x - radius; x <= center_x + radius; x++)
	{
		for (int y = center_y - radius; y <= center_y + radius; y++)
		{
			// Check if the current pixel is within the circle using the circle equation
			if ((x - center_x) * (x - center_x) + (y - center_y) * (y - center_y) <= radius * radius)
			{
				mlx_put_pixel(data->minimap, x, y, 0xff0000AA);
			}
		}
	}
	draw_vision_line(data, center_x, center_y, (int)line_end_x, (int)line_end_y);
}
