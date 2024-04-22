/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 16:14:15 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_pressed(int key, t_data *data)
{
	printf("A key has been pressed\n");
	(void)data;
	if (key == MLX_KEY_UP)
	{
//		data->img_player->instances[0].y -= data->tile_height;
//		data->player_y--;
	}
	else if (key == MLX_KEY_DOWN)
	{
//		data->img_player->instances[0].y += data->tile_height;
//		data->player_y++;
	}
	else if (key == MLX_KEY_LEFT)
	{
//		data->img_player->instances[0].x -= data->tile_width;
//		data->player_x--;
	}
	else if (key == MLX_KEY_RIGHT)
	{
//		data->img_player->instances[0].x += data->tile_width;
//		data->player_x++;
	}
}

void	player_input(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(data->mlx);
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
//			if (data->map[data->player_y - 1][data->player_x] != '1')
				key_pressed(MLX_KEY_UP, data);
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
//			if (data->map[data->player_y + 1][data->player_x] != '1')
				key_pressed(MLX_KEY_DOWN, data);
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
//			if (data->map[data->player_y][data->player_x - 1] != '1')
				key_pressed(MLX_KEY_LEFT, data);
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
//			if (data->map[data->player_y][data->player_x + 1] != '1')
				key_pressed(MLX_KEY_RIGHT, data);
	}
}
