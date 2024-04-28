/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/04/28 18:36:54 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	paint_sky_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
			mlx_put_pixel(data->world, x, y++, data->sky_color);
		while (y < HEIGHT)
			mlx_put_pixel(data->world, x, y++, data->floor_color);
		x++;
	}
}

void	paint_world(t_data *data)
{
	paint_sky_floor(data);
	paint_walls(data);
}

void	initialise_world(t_data *data)
{
	data->world = mlx_new_image(data->mlx, WIDTH, HEIGHT);
//	if (!data->world)
		// handle error
	mlx_image_to_window(data->mlx, data->world, 0, 0);
	
//	data->buffer_world = mlx_new_image(data->mlx, WIDTH, HEIGHT);
//	mlx_image_to_window(data->mlx, data->buffer_world, 0, 0);
//	data->buffer_world->enabled = false;
//	if (!data->buffer_world)
		// handle error
}
