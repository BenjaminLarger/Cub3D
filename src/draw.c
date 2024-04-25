/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:53:42 by blarger           #+#    #+#             */
/*   Updated: 2024/04/25 14:30:47 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ground(t_data *data, int ray_index, int distance_to_wall)
{
	int		y;
	int		i;
//use proportion ?
	i = 0;
	y = HEIGHT;
	while (i < distance_to_wall * 10)
	{
		mlx_put_pixel(data->window, ray_index, y, 0xffaa00AA);
		y--;
		i++;
	}
}
