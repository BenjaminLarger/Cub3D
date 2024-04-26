/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/26 11:03:03 by blarger          ###   ########.fr       */
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
	/* x = data->player_x + cos(data->player_angle) * speed;
	y = data->player_y + sin(data->player_angle) * speed; */
	if (key == MLX_KEY_W)
	{
		x = data->player_x + cos(data->player_angle) * speed;
		y = data->player_y + sin(data->player_angle) * speed;
		if (can_move(data->map[(int)(y)][(int)x]))
		{
			data->player_y = y;
			data->player_x = x;	
		}
		else
			data->player_y = (int)round(y - speed) + 0.1;
	}
	else if (key == MLX_KEY_S)
	{
		x = data->player_x - cos(data->player_angle) * speed;
		y = data->player_y - sin(data->player_angle) * speed;
		if (can_move(data->map[(int)(y)][(int)x]))
		{
			data->player_y = y;
			data->player_x = x;
		}
		else
			data->player_y = (int)round(y + speed) - 0.1;
	}
	else if (key == MLX_KEY_A)
	{
		x = data->player_x - (cos(data->player_angle) * speed * 0.5);
		y = data->player_y - (sin(data->player_angle) * speed * 0.5);
		if (can_move(data->map[(int)y][(int)(x)]))
		{
			data->player_y = y;
			data->player_x = x;
		}
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

void	player_input(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	else if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(MLX_KEY_LEFT, data);
	else if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		rotate_player(MLX_KEY_RIGHT, data);
	else if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(MLX_KEY_W, data);
	else if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(MLX_KEY_S, data);
	else if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(MLX_KEY_A, data);
	else if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT))
		move_player(MLX_KEY_D, data);
}
