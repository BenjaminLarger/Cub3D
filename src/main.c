/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:08 by demre             #+#    #+#             */
/*   Updated: 2024/04/24 08:43:44 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void hook(void* param)
{
	t_data	*data;

	data = (t_data *)param;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_and_exit("Wrong arg number", 2, EXIT_FAILURE);
	initialise(argv[1], &data);
	mlx_loop_hook(data.mlx, hook, &data);
	mlx_key_hook(data.mlx, &player_input, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
	exit(EXIT_SUCCESS);
}
