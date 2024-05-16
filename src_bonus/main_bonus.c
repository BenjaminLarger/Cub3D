/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:08 by demre             #+#    #+#             */
/*   Updated: 2024/05/16 12:57:55 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	render(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->loop++;
	if (data->loop == 8)
		data->loop = 0;
	player_input(data);
	check_close_door(data);
	paint_world(data);
	if (data->display_minimap == TRUE)
		paint_minimap(data);
	paint_sprite(data);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		print_and_exit("Wrong arg number", 2, EXIT_FAILURE);
	initialise(argv[1], &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_key_hook(data.mlx, &minimap_control, &data);
	mlx_cursor_hook(data.mlx, &mouse_control, &data);
	mlx_loop(data.mlx);
	exit_game(&data);
	exit(EXIT_SUCCESS);
}
