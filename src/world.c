/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/04/29 15:23:45 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	paint_world(t_data *data)
{
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
