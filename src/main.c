/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:08 by demre             #+#    #+#             */
/*   Updated: 2024/04/29 18:04:01 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void copy_mlx_image_pixels(const mlx_image_t *src, mlx_image_t *dest)
{
	if (!src || !dest || !src->pixels || !dest->pixels)
		return ;

	ft_memcpy(dest->pixels, src->pixels,
		src->width * src->height * sizeof(uint8_t));
	dest->instances = src->instances;
	dest->count = src->count;
	dest->context = src->context;
}
static void render(void* param)
{
	t_data	*data;

	data = (t_data *)param;

//	copy_mlx_image_pixels(data->world, data->buffer_world);
//	data->buffer_world->enabled = true;
//	data->world->enabled = false;
	player_input(data);
	paint_world(data);
	paint_minimap(data);
//	data->world->enabled = true;
//	data->buffer_world->enabled = false;

	display_fps(); // to delete
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_and_exit("Wrong arg number", 2, EXIT_FAILURE);
	initialise(argv[1], &data);
	mlx_loop_hook(data.mlx, render, &data);
	//mlx_key_hook(data.mlx, &player_input, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
//	atexit(check_leaks);
	exit(EXIT_SUCCESS);
}
