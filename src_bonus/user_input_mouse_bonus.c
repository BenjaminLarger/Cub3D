/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_mouse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:25:08 by demre             #+#    #+#             */
/*   Updated: 2024/05/16 12:58:21 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_player_angle(t_data *data, double diff_mouse_x,
	double angle_rotate)
{
	if (diff_mouse_x >= 0)
	{
		if (data->player_angle - angle_rotate >= 0)
			data->player_angle -= angle_rotate;
		else
			data->player_angle = (2 * M_PI + data->player_angle) - angle_rotate;
	}
	else if (diff_mouse_x < 0)
	{
		if (data->player_angle + angle_rotate < 2 * M_PI)
			data->player_angle += angle_rotate;
		else
			data->player_angle = angle_rotate - (2 * M_PI - data->player_angle);
	}
}

void	mouse_control(double xpos, double ypos, void *param)
{
	t_data	*data;
	double	diff_mouse_x;
	double	angle_rotate;

	data = (t_data *)param;
	(void)ypos;
	if (data->prev_mouse_x == -1)
		data->prev_mouse_x = xpos;
	diff_mouse_x = data->prev_mouse_x - xpos;
	data->prev_mouse_x = xpos;
	if (fabs(diff_mouse_x) > 20)
		angle_rotate = M_PI * 0.07;
	else
		angle_rotate = M_PI * fabs(diff_mouse_x) / 1000;
	set_player_angle(data, diff_mouse_x, angle_rotate);
}
