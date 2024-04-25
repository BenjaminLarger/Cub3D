/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/25 12:49:32 by demre            ###   ########.fr       */
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
	if (key == MLX_KEY_W)
	{
		data->player_y = data->player_y * (1 - 0.01);
	}
	else if (key == MLX_KEY_S)
	{
		data->player_y = data->player_y * (1 + 0.01);
	}
	else if (key == MLX_KEY_A)
	{
		data->player_x = data->player_x * (1 - 0.01);
	}
	else if (key == MLX_KEY_D)
	{
		data->player_x = data->player_x * (1 + 0.01);
	}
	printf("(x,y) (%f:%f)\n", data->player_x, data->player_y);
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
