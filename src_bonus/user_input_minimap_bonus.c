/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input_minimap_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 08:49:36 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	toggle_display_minimap(t_data *data)
{
	if (data->display_minimap == TRUE)
		data->display_minimap = FALSE;
	else
		data->display_minimap = TRUE;
	mlx_delete_image(data->mlx, data->minimap);
	initialise_minimap(data);
	paint_minimap(data);
}

static void	resize_minimap(int key, t_data *data)
{
	if (key == MLX_KEY_KP_SUBTRACT)
		data->minimap_tile_px /= 2;
	else if (key == MLX_KEY_KP_ADD)
		data->minimap_tile_px *= 2;
	if (data->minimap_tile_px < 4)
		data->minimap_tile_px = 4;
	else if (data->minimap_tile_px > 32)
		data->minimap_tile_px = 32;
	mlx_delete_image(data->mlx, data->minimap);
	initialise_minimap(data);
	paint_minimap(data);
}

void	minimap_control(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_KP_SUBTRACT && keydata.action == MLX_PRESS)
		resize_minimap(MLX_KEY_KP_SUBTRACT, data);
	else if (keydata.key == MLX_KEY_KP_ADD && keydata.action == MLX_PRESS)
		resize_minimap(MLX_KEY_KP_ADD, data);
	else if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		toggle_display_minimap(data);
	else if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		open_door(data);
}
