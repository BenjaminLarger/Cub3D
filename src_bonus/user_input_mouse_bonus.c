/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_mouse_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:25:08 by demre             #+#    #+#             */
/*   Updated: 2024/05/14 15:07:39 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	mouse_control(double xpos, double ypos, void *param)
{
	t_data	*data;
	double	angle_rotate;
	
	data = (t_data *)param;
	(void)ypos;
	if (data->prev_mouse_x == -1)
		data->prev_mouse_x = xpos;
	data->diff_mouse_x = data->prev_mouse_x - xpos;
	data->prev_mouse_x = xpos;

	if (fabs(data->diff_mouse_x) > 20)
		angle_rotate = M_PI * 0.07;
	else
		angle_rotate = M_PI * fabs(data->diff_mouse_x) / 1000;
	if (data->diff_mouse_x >= 0)
	{
		if (data->player_angle - angle_rotate >= 0)
			data->player_angle -= angle_rotate;
		else
			data->player_angle = (2 * M_PI + data->player_angle) - angle_rotate;
	}
	else if (data->diff_mouse_x < 0)
	{
		if (data->player_angle + angle_rotate < 2 * M_PI)
			data->player_angle += angle_rotate;
		else
			data->player_angle = angle_rotate - (2 * M_PI - data->player_angle);
	}
	if (data->paint_in_render == FALSE)
	{
		paint_world(data);
		paint_minimap(data);
	}
}
