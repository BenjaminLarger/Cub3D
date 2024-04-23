/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:55:53 by demre             #+#    #+#             */
/*   Updated: 2024/04/23 12:03:54 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(t_data *data)
{
	mlx_terminate(data->mlx);
	free_string_array(data->map);
	free(data->north_path);
	free(data->south_path);
	free(data->west_path);
	free(data->east_path);
	free(data->floor_color);
	free(data->ceiling_color);
}
