/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:54:02 by demre             #+#    #+#             */
/*   Updated: 2024/05/12 15:25:31 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_field_of_view(t_data *data)
{
	t_pfv	pfv;

	pfv.i = 0;
	pfv.view_angle = PLAYER_FOV * (M_PI / 180);
	pfv.angle_step = pfv.view_angle / NUM_OF_RAYS; //200 = nmumber of rays
	while (pfv.i < NUM_OF_RAYS)
	{
		pfv.ray_angle = data->player_angle
			- (pfv.view_angle / 2) + pfv.i * pfv.angle_step;
		pfv.ray_length = get_wall_distance(data, pfv.ray_angle);
		pfv.endX = pfv.ray_length * cos(pfv.ray_angle);
		pfv.endY = pfv.ray_length * sin(pfv.ray_angle);
//	printf("pfv.endX: %f, pfv.endY: %f, pfv.ray_length: %f\n", pfv.endX, pfv.endY, pfv.ray_length);
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

static void	get_mm_start_end_row(t_data *data)
{
	if (data->player_y - data->mm_max_row / 2 <= 0)
	{
		data->mm_row_start_px = 0;
		data->mm_row_end_px = data->mm_max_row;
	}
	else if (data->player_y + data->mm_max_row / 2 > data->row)
	{
		data->mm_row_start_px = data->row - data->mm_max_row;
		data->mm_row_end_px = data->row;
	}
	else
	{
		data->mm_row_start_px = data->player_y - data->mm_max_row / 2;
		data->mm_row_end_px = data->player_y + data->mm_max_row / 2;
	}
}

static void	get_mm_start_end_col(t_data *data)
{
	if (data->player_x - data->mm_max_col / 2 <= 0)
	{
		data->mm_col_start_px = 0;
		data->mm_col_end_px = data->mm_max_col;
	}
	else if (data->player_x + data->mm_max_col / 2 > data->col)
	{
		data->mm_col_start_px = data->col - data->mm_max_col;
		data->mm_col_end_px = data->col;
	}
	else
	{
		data->mm_col_start_px = data->player_x - data->mm_max_col / 2;
		data->mm_col_end_px = data->player_x + data->mm_max_col / 2;
	}
}

static uint32_t	get_mm_px_color(t_data *data,
	unsigned int mm_x, unsigned int mm_y)
{
	unsigned int	col;
	unsigned int	row;
	uint32_t		color;
	char			pos;

	col = (mm_x + (data->mm_col_start_px * data->minimap_tile_px))
		/ data->minimap_tile_px;
	row = (mm_y + (data->mm_row_start_px * data->minimap_tile_px))
		/ data->minimap_tile_px;
	if (col >= data->col || row >= data->row)
		pos = OUT;
	else
		pos = data->map[row][col];
	if (pos == WALL)
		color = 0xaaaaaa99;
	else if (pos != OUT && pos != '2')
		color = 0x11111199;
	else
		color = 0x00000000;
	return (color);
}

void	paint_minimap(t_data *data)
{
	unsigned int	mm_x;
	unsigned int	mm_y;

	if (data->display_minimap == TRUE)
	{
		mm_x = 0;
		mm_y = 0;
		get_mm_start_end_row(data);
		get_mm_start_end_col(data);
		while (mm_x < data->mm_max_width_px)
		{
			mm_y = 0;
			while (mm_y < data->mm_max_height_px)
			{
				mlx_put_pixel(data->minimap,
					mm_x, mm_y,
					get_mm_px_color(data, mm_x, mm_y));
				mm_y++;
			}
			mm_x++;
		}
//		paint_field_of_view(data); //
		paint_mm_player(data);
	}
}

void	initialise_minimap(t_data *data)
{
	data->mm_max_width_px = 480; // 16 * 30
	data->mm_max_height_px = 320; // 16 * 20
	data->mm_max_col = data->mm_max_width_px / data->minimap_tile_px; // 30
	data->mm_max_row = data->mm_max_height_px / data->minimap_tile_px; // 20
	data->minimap = mlx_new_image(data->mlx,
					data->mm_max_width_px,
					data->mm_max_height_px);
	mlx_image_to_window(data->mlx, data->minimap, 32, 32);
}
