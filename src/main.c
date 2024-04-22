/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:08 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 15:00:59 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* static void hook(void* param)
{
	const mlx_t* mlx = param;
} */

int	main(int argc, char **argv)
{
//	t_data	data;
	(void)argv;
	if (argc != 2)
		print_and_exit("Wrong arg number", 2, EXIT_FAILURE);
	
	mlx_t* mlx = mlx_init(2500, 1250, "cub3d", false);
	if (!mlx)
		printf("Error");

//	mlx_loop_hook(mlx, hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
