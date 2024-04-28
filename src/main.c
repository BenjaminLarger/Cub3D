/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:08 by demre             #+#    #+#             */
/*   Updated: 2024/04/28 18:37:25 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void render(void* param)
{
	t_data	*data;

	data = (t_data *)param;

	paint_world(data);
	paint_minimap(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_and_exit("Wrong arg number", 2, EXIT_FAILURE);
	initialise(argv[1], &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_key_hook(data.mlx, &player_input, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
//	atexit(check_leaks);
	exit(EXIT_SUCCESS);
}
