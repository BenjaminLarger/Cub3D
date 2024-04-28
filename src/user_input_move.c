/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/28 15:20:07 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	double	end_x;
	double	end_y;

	end_x = (data->player_speed / 10) * cos(data->player_angle);
	end_y = (data->player_speed / 10) * sin(data->player_angle);
//	printf("(player_x) : (player_y)				(%f:%f)\n", data->player_x, data->player_y);
//	printf("(player_x + end_x) : (player_y + end_y)		(%f:%f)\n", (data->player_x + end_x), (data->player_y + end_y));
//	printf("(int)(player_x + end_x) : (int)(player_y + end_y) (%d:%d)\n", (int)(data->player_x + end_x), (int)(data->player_y + end_y));
//	printf("(int)round(player_x + end_x) : (int)round(player_y + end_y) (%d:%d)\n", (int)round(data->player_x + end_x), (int)round(data->player_y + end_y));

	if (can_move(data->map[(int)(data->player_y + end_y)][(int)(data->player_x + end_x)]))
	{
		data->player_x += end_x;
		data->player_y += end_y;
	}
//	else
//	{
//		data->player_x = (int)round(data->player_x + end_x) - 0.1;
//		data->player_y = (int)round(data->player_y + end_y) - 0.1;
	//	data->player_y = (int)round(data->player_y - speed) + 0.1;
//	}

//	printf("x,y (%f:%f)\n", data->player_x, data->player_y);
}

void	move_backward(t_data *data)
{
	double	end_x;
	double	end_y;

	end_x = (data->player_speed / 10) * cos(data->player_angle);
	end_y = (data->player_speed / 10) * sin(data->player_angle);
//	printf("(player_x) : (player_y)				(%f:%f)\n", data->player_x, data->player_y);
//	printf("(player_x - end_x) : (player_y - end_y)		(%f:%f)\n", (data->player_x - end_x), (data->player_y - end_y));
//	printf("(int)(player_x - end_x) : (int)(player_y - end_y) (%d:%d)\n", (int)(data->player_x - end_x), (int)(data->player_y - end_y));
//	printf("(int)round(player_x - end_x) : (int)round(player_y - end_y) (%d:%d)\n", (int)round(data->player_x - end_x), (int)round(data->player_y - end_y));

	if (can_move(data->map[(int)(data->player_y - end_y)][(int)(data->player_x - end_x)]))
	{
		data->player_x -= end_x;
		data->player_y -= end_y;
	}
//	else
//	{
//		data->player_x = (int)round(data->player_x - end_x) - 0.1;
//		data->player_y = (int)round(data->player_y - end_y) - 0.1;
	//	data->player_y = (int)round(data->player_y + speed) - 0.1;
//	}

//	printf("x,y (%f:%f)\n", data->player_x, data->player_y);
}

void	move_right(t_data *data)
{
	double	end_x;
	double	end_y;

	end_x = (data->player_speed / 10) * cos(data->player_angle - M_PI_2);
	end_y = (data->player_speed / 10) * sin(data->player_angle - M_PI_2);
//	printf("(player_x) : (player_y)				(%f:%f)\n", data->player_x, data->player_y);
//	printf("(player_x - end_x) : (player_y - end_y)		(%f:%f)\n", (data->player_x - end_x), (data->player_y - end_y));
//	printf("(int)(player_x - end_x) : (int)(player_y - end_y) (%d:%d)\n", (int)(data->player_x - end_x), (int)(data->player_y - end_y));
//	printf("(int)round(player_x - end_x) : (int)round(player_y - end_y) (%d:%d)\n", (int)round(data->player_x - end_x), (int)round(data->player_y - end_y));

	if (can_move(data->map[(int)(data->player_y - end_y)][(int)(data->player_x - end_x)]))
	{
		data->player_x -= end_x;
		data->player_y -= end_y;
	}
//	else
//	{
//		data->player_x = (int)round(data->player_x - end_x) - 0.1;
//		data->player_y = (int)round(data->player_y - end_y) - 0.1;
	//	data->player_y = (int)round(data->player_y + speed) - 0.1;
//	}

//	printf("x,y (%f:%f)\n", data->player_x, data->player_y);
}

void	move_left(t_data *data)
{
	double	end_x;
	double	end_y;

	end_x = (data->player_speed / 10) * cos(data->player_angle + M_PI_2);
	end_y = (data->player_speed / 10) * sin(data->player_angle + M_PI_2);
//	printf("(player_x) : (player_y)				(%f:%f)\n", data->player_x, data->player_y);
//	printf("(player_x - end_x) : (player_y - end_y)		(%f:%f)\n", (data->player_x - end_x), (data->player_y - end_y));
//	printf("(int)(player_x - end_x) : (int)(player_y - end_y) (%d:%d)\n", (int)(data->player_x - end_x), (int)(data->player_y - end_y));
//	printf("(int)round(player_x - end_x) : (int)round(player_y - end_y) (%d:%d)\n", (int)round(data->player_x - end_x), (int)round(data->player_y - end_y));

	if (can_move(data->map[(int)(data->player_y - end_y)][(int)(data->player_x - end_x)]))
	{
		data->player_x -= end_x;
		data->player_y -= end_y;
	}
//	else
//	{
//		data->player_x = (int)round(data->player_x - end_x) - 0.1;
//		data->player_y = (int)round(data->player_y - end_y) - 0.1;
	//	data->player_y = (int)round(data->player_y + speed) - 0.1;
//	}

//	printf("x,y (%f:%f)\n", data->player_x, data->player_y);
}
