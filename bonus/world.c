/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 11:58:42 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 12:36:41 by blarger          ###   ########.fr       */
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
	if (!data->world
		|| mlx_image_to_window(data->mlx, data->world, 0, 0) < 0)
		print_and_exit("Failed to initialise image", 2, EXIT_FAILURE);
}
