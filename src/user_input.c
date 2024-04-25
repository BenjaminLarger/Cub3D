/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/25 18:30:16 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_player(int key, t_data *data)
{
	double	angle_rotate;

	angle_rotate = 2 * M_PI * data->player_speed / 100;
	if (key == MLX_KEY_LEFT)
	{
		if (data->player_angle - angle_rotate >= 0)
			data->player_angle -= angle_rotate;
		else
			data->player_angle = (2 * M_PI + data->player_angle) - angle_rotate;
		printf("data->player_angle: %f : %f\n", data->player_angle, data->player_angle * 180 / M_PI);
	}
	else if (key == MLX_KEY_RIGHT)
	{
		if (data->player_angle + angle_rotate < 2 * M_PI)
			data->player_angle += angle_rotate;
		else
			data->player_angle = angle_rotate - (2 * M_PI - data->player_angle);
		printf("data->player_angle: %f : %f\n", data->player_angle, data->player_angle * 180 / M_PI);
	}
	paint_minimap(data);
}

void	move_player(int key, t_data *data)
{
	double	x;
	double	y;
	double	speed;

	speed = data->player_speed / 10;
	x = data->player_x;
	y = data->player_y;
	if (key == MLX_KEY_W)
	{
		if (can_move(data->map[(int)(y - speed)][(int)x]))
			data->player_y -= speed;
		else
			data->player_y = (int)round(y - speed) + 0.1;
	}
	else if (key == MLX_KEY_S)
	{
		if (can_move(data->map[(int)(y + speed)][(int)x]))
			data->player_y += speed;
		else
			data->player_y = (int)round(y + speed) - 0.1;
	}
	else if (key == MLX_KEY_A)
	{
		if (can_move(data->map[(int)y][(int)(x - speed)]))
			data->player_x -= speed;
		else
			data->player_x = (int)round(x - speed) + 0.1;
	}
	else if (key == MLX_KEY_D)
	{
		if (can_move(data->map[(int)y][(int)(x + speed)]))
			data->player_x += speed;
		else
			data->player_x = (int)round(x + speed) - 0.1;
	}
	printf("x,y (%f:%f)\n", data->player_x, data->player_y);
	paint_minimap(data);
}

static void	resize_minimap(int key, t_data *data)
{
	if (key == MLX_KEY_KP_SUBTRACT)
		data->minimap_tile_px /= 2;
	else if (key == MLX_KEY_KP_ADD)
		data->minimap_tile_px *= 2;
	if (data->minimap_tile_px < 2)
		data->minimap_tile_px = 2;
	else if (data->minimap_tile_px > 32)
		data->minimap_tile_px = 32;
	mlx_delete_image(data->mlx, data->minimap);
	data->minimap = mlx_new_image(data->mlx,
			data->col * data->minimap_tile_px,
			data->row * data->minimap_tile_px);
	mlx_image_to_window(data->mlx, data->minimap, 32, 32);
	paint_minimap(data);
}

void	player_input(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	else if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_LEFT)
			rotate_player(MLX_KEY_LEFT, data);
		else if (keydata.key == MLX_KEY_RIGHT)
			rotate_player(MLX_KEY_RIGHT, data);
		else if (keydata.key == MLX_KEY_W)
			move_player(MLX_KEY_W, data);
		else if (keydata.key == MLX_KEY_S)
			move_player(MLX_KEY_S, data);
		else if (keydata.key == MLX_KEY_A)
			move_player(MLX_KEY_A, data);
		else if (keydata.key == MLX_KEY_D)
			move_player(MLX_KEY_D, data);
		else if (keydata.key == MLX_KEY_KP_SUBTRACT
			|| keydata.key == MLX_KEY_KP_ADD)
			resize_minimap(keydata.key, data);
	}
}
