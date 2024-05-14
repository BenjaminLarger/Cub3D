/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/05/14 12:08:03 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	double	end_x;
	double	end_y;

	end_x = (data->player_speed / 10) * cos(data->player_angle) * 4;
	end_y = (data->player_speed / 10) * sin(data->player_angle) * 4;
	if (player_can_move(data, end_x, end_y) == true)
	{
		data->player_x += (end_x / 4);
		data->player_y += (end_y / 4);
	}
}

void	move_backward(t_data *data)
{
	double	end_x;
	double	end_y;

	end_x = (data->player_speed / 10) * cos(data->player_angle) * 4;
	end_y = (data->player_speed / 10) * sin(data->player_angle) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
}

void	move_right(t_data *data)
{
	double	end_x;
	double	end_y;

	end_x = (data->player_speed / 10) * cos(data->player_angle - M_PI_2) * 4;
	end_y = (data->player_speed / 10) * sin(data->player_angle - M_PI_2) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
}

void	move_left(t_data *data)
{
	double	end_x;
	double	end_y;

	end_x = (data->player_speed / 10) * cos(data->player_angle + M_PI_2) * 4;
	end_y = (data->player_speed / 10) * sin(data->player_angle + M_PI_2) * 4;
	if (player_can_move(data, -end_x, -end_y) == true)
	{
		data->player_x -= end_x / 4;
		data->player_y -= end_y / 4;
	}
}
