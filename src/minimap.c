/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 11:54:02 by demre             #+#    #+#             */
/*   Updated: 2024/04/27 14:37:14 by blarger          ###   ########.fr       */
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
		else if (line[col] != OUT && line[col] != '2')
			paint_one_tile(data, 0x11111199, col, row);
		col++;
	}
}

static void	paint_player(t_data *data)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	pos_x;
	unsigned int	pos_y;

	x = data->minimap_tile_px / 4;
	while (x < data->minimap_tile_px - data->minimap_tile_px / 4)
	{
		y = data->minimap_tile_px / 4;
		while (y < data->minimap_tile_px - data->minimap_tile_px / 4)
		{
			pos_x = (data->player_x - 0.5) * data->minimap_tile_px + x;
			pos_y = (data->player_y - 0.5) * data->minimap_tile_px + y;
			mlx_put_pixel(data->minimap, pos_x, pos_y, 0xff0000AA);
			y++;
		}
		x++;
	}
}

/* double	get_next_y_edge(t_data *data, t_edge *edge, double ray_angle)
{
	double	next_x_edge;

	if (ray_angle > M_PI)//direction to next y
		next_x_edge = floor(cur_axis / data->minimap_tile_px) * data->minimap_tile_px + data->minimap_tile_px;
	else//direction to previous y
		next_x_edge = floor(cur_axis / data->minimap_tile_px) * data->minimap_tile_px;
	return (next_x_edge);
}

double	get_next_x_edge(t_data *data, t_edge *edge, double ray_angle)
{
	edge->new_x1 = (sin(ray_angle) / cos(ray_angle)) * (ceil(edge->ray_y));
	edge->new_y1 = ceil(edge->ray_y);
	
} */

double	get_next_x_edge(t_data *data, t_edge *edge, double ray_angle)
{
	double	ray_slope;

	ray_slope = tan(ray_angle);
	if (cos(ray_angle) > 0)
		edge->new_x1 = ceil(edge->ray_x);
	else
		edge->new_x1 = floor(edge->ray_x);
	edge->new_y1 = edge->ray_y + (edge->new_x1 - edge->ray_x) * ray_slope;
}

double	get_next_y_edge(t_data *data, t_edge *edge, double ray_angle)
{
	double	ray_slope;
	double	next_x_edge;
	double	next_y_edge;

	if (cos(ray_angle) > 0)
		next_x_edge = ceil(edge->ray_x);
	else
		next_x_edge = floor(edge->ray_x);
	next_y_edge = edge->ray_y + (next_x_edge - edge->ray_x) * ray_slope;
	edge->ray_x = next_x_edge;
	edge->ray_y;
}

static double	get_line_length(t_data *data, double ray_angle)
{
	t_edge	edge;

	edge.distance_to_wall = 0;
	edge.ray_x = data->player_x;
	edge.ray_y = data->player_y;
	edge.ray_dx = cos(ray_angle) * 0.001;
	edge.ray_dy = sin(ray_angle) * 0.001;
	while (1)
	{
		edge.distance_to_wall += 0.001;
		edge.ray_x += edge.ray_dx;
		edge.ray_y += edge.ray_dy;
		if (can_move(data->map[(int)edge.ray_y][(int)edge.ray_x]) == false)
			break ;
	}
	return (edge.distance_to_wall);
}

static void	paint_field_of_view(t_data *data)
{
	t_pfv	pfv;

	pfv.i = 0;
	pfv.view_angle = PLAYER_FOV * (M_PI / 180);
	pfv.angle_step = pfv.view_angle / NUM_OF_RAYS; //200 = nmumber of rays
	while (pfv.i < NUM_OF_RAYS)
	{
		pfv.ray_angle = data->player_angle
			- (pfv.view_angle / 2) + pfv.i * pfv.angle_step;
		pfv.ray_length = get_line_length(data, pfv.ray_angle);
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

/* static void	paint_ruler(t_data *data)
{
	unsigned int	row;
	unsigned int	col;
	char			*temp_str;

	printf("paint_ruler\n");
	row = 0;
	col = 0;
	while (data->map[row][col])
	{
		temp_str = ft_itoa(col);
		mlx_put_string(data->mlx,
			temp_str,
			col + 32 + col * data->minimap_tile_px,
			row + 32);
		free(temp_str);
		col++;
	}
	col = 0;
	row = 1;
	while (data->map[row])
	{
		temp_str = ft_itoa(row);
		mlx_put_string(data->mlx,
			temp_str,
			col + 32,
			row + 32 + row * data->minimap_tile_px);
		free(temp_str);
		row++;
	}
} */

void	paint_minimap(t_data *data)
{
	unsigned int	row;

	row = 0;
	while (data->map[row])
	{
		paint_line(data->map[row], data, row);
		row++;
	}
	paint_field_of_view(data);
	paint_player(data);
//	paint_ruler(data); // to delete
}

void	initialise_minimap(t_data *data)
{
	data->minimap = mlx_new_image(data->mlx,
			data->col * data->minimap_tile_px,
			data->row * data->minimap_tile_px);
	mlx_image_to_window(data->mlx, data->minimap, 32, 32);
}
