/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:55:53 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 18:39:04 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	exit_game(t_data *data)
{
	if (data->display_minimap == TRUE)
		mlx_delete_image(data->mlx, data->minimap);
	mlx_delete_image(data->mlx, data->sprite);
	mlx_delete_image(data->mlx, data->world);
	mlx_delete_texture(data->wall_no);
	mlx_delete_texture(data->wall_so);
	mlx_delete_texture(data->wall_we);
	mlx_delete_texture(data->wall_ea);
	mlx_delete_texture(data->door_close);
	mlx_delete_texture(data->sprite_texture1);
	mlx_delete_texture(data->sprite_texture2);
	mlx_delete_texture(data->sprite_texture3);
	mlx_delete_texture(data->sprite_texture4);
	mlx_terminate(data->mlx);
	free_string_array(data->map);
}
