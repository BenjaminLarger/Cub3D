/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_move_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 20:46:50 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/* # define FORWARD "Forward"
# define BACKWARD "Backward"
# define RIGHT "Right"
# define LEFT "Left"

# define HW 1 //horizontal wall
# define VW 2 //vertical wall */


void	move_forward(t_data *data)
{
	double	end_x;
	double	end_y;
	double	speed;

	speed = data->player_speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		speed = data->player_speed / 2;
	}
	end_x = (speed / 10) * cos(data->player_angle) * 4;
	end_y = (speed / 10) * sin(data->player_angle) * 4;
	if (player_can_move(data, end_x, end_y) == true)
	{
		data->player_x += (end_x / 4);
		data->player_y += (end_y / 4);
	}
	else
		player_slide_on_wall(data, FORWARD, end_x, end_y);
	if (data->paint_in_render == FALSE)
	{
		paint_world(data);
		paint_minimap(data);
	}
}

void	move_backward(t_data *data)
{
	double	end_x;
	double	end_y;
	double	speed;

	speed = data->player_speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_D))
	{
		speed = data->player_speed / 2;
	}
	end_x = (speed / 10) * cos(data->player_angle) * 4;
	end_y = (speed / 10) * sin(data->player_angle) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
	else
		player_slide_on_wall(data, BACKWARD, end_x, end_y);
	if (data->paint_in_render == FALSE)
	{
		paint_world(data);
		paint_minimap(data);
	}
}

void	move_right(t_data *data)
{
	double	end_x;
	double	end_y;
	double	speed;

	speed = data->player_speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		speed = data->player_speed / 2;
	}
	end_x = (speed / 10) * cos(data->player_angle - M_PI_2) * 4;
	end_y = (speed / 10) * sin(data->player_angle - M_PI_2) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
	if (data->paint_in_render == FALSE)
	{
		paint_world(data);
		paint_minimap(data);
	}
}

void	move_left(t_data *data)
{
	double	end_x;
	double	end_y;
	double	speed;

	speed = data->player_speed;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_S))
	{
		speed = data->player_speed / 2;
	}
	end_x = (speed / 10) * cos(data->player_angle + M_PI_2) * 4;
	end_y = (speed / 10) * sin(data->player_angle + M_PI_2) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
	if (data->paint_in_render == FALSE)
	{
		paint_world(data);
		paint_minimap(data);
	}
}
