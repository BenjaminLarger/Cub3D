/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:33:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/25 12:25:11 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key_pressed(int key, t_data *data)
{
	double	angle_rotate;

	angle_rotate = 2 * M_PI * data->player_speed / 100;
	printf("A key has been pressed\n");
	if (key == MLX_KEY_UP)
	{
		for (uint32_t x = 0; x < WIDTH; ++x)
		{
			for (uint32_t y = 0; y < HEIGHT / 2; ++y)
			{
				mlx_put_pixel(data->window, x, y, 0xabcdefFF);
			}
		}
		data->test = mlx_texture_to_image(data->mlx, data->wall_no);
		mlx_image_to_window(data->mlx, data->test, WIDTH / 3, HEIGHT / 4);
	}
	else if (key == MLX_KEY_DOWN)
	{
		for (uint32_t x = 0; x < WIDTH; ++x)
		{
			for (uint32_t y = HEIGHT / 2; y < HEIGHT; ++y)
			{
				mlx_put_pixel(data->window, x, y, 0xcbacbaFF);
			}
		}
		data->test = mlx_texture_to_image(data->mlx, data->wall_so);
		mlx_image_to_window(data->mlx, data->test, WIDTH / 3, HEIGHT / 4);
//		data->img_player->instances[0].y += data->tile_height;
//		data->player_y++;
	}
	else if (key == MLX_KEY_LEFT)
	{
		if (data->player_angle - angle_rotate >= 0)
			data->player_angle -= angle_rotate;
		else
			data->player_angle = (2 * M_PI + data->player_angle) - angle_rotate;
		printf("data->player_angle: %f : %f\n", data->player_angle, data->player_angle * 180 / M_PI);
	}
	else if (key == MLX_KEY_RIGHT)
	{
		if (data->player_angle + angle_rotate < 2 * M_PI)
			data->player_angle += angle_rotate;
		else
			data->player_angle = angle_rotate - (2 * M_PI - data->player_angle);
		printf("data->player_angle: %f : %f\n", data->player_angle, data->player_angle * 180 / M_PI);
	}
	paint_minimap(data);
}


void	move_player(int key, t_data *data)
{
	(void)data;
	(void)key;
	if (key == MLX_KEY_W)
	{
		data->player_y = data->player_y * (1 - 0.01);
		printf("x = %f\n", data->player_y);
	}
	else if (key == MLX_KEY_S)
	{
		data->player_y = data->player_y * (1 + 0.01);
		printf("x = %f\n", data->player_y);
	}
	else if (key == MLX_KEY_A)
	{
		data->player_x = data->player_x * (1 - 0.01);
		printf("x = %f\n", data->player_x);
	}
	else if (key == MLX_KEY_D)
	{
		data->player_x = data->player_x * (1 + 0.01);
		printf("x = %f\n", data->player_x);
	}
	paint_minimap(data);
}

/* void	player_input(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		move_player(MLX_KEY_W, data);
	if (keydata.action == MLX_PRESS)
	{
		if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
			mlx_close_window(data->mlx);
		if (keydata.key == MLX_KEY_UP)
				key_pressed(MLX_KEY_UP, data);
//			if (data->map[data->player_y - 1][data->player_x] != '1')
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
				key_pressed(MLX_KEY_DOWN, data);
//			if (data->map[data->player_y + 1][data->player_x] != '1')
		if ((keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A))
		{
			//while (keydata.action != MLX_RELEASE)
				key_pressed(MLX_KEY_LEFT, data);
		}
//				if (data->map[data->player_y][data->player_x - 1] != '1')
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
				key_pressed(MLX_KEY_RIGHT, data);
//			if (data->map[data->player_y][data->player_x + 1] != '1')
	}
} */

void	player_input(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		key_pressed(MLX_KEY_LEFT, data);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		key_pressed(MLX_KEY_RIGHT, data);
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_REPEAT)
		key_pressed(MLX_KEY_LEFT, data);
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_REPEAT)
		key_pressed(MLX_KEY_RIGHT, data);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		move_player(MLX_KEY_W, data);
	else if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		move_player(MLX_KEY_W, data);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		move_player(MLX_KEY_S, data);
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		move_player(MLX_KEY_S, data);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		move_player(MLX_KEY_A, data);
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		move_player(MLX_KEY_A, data);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		move_player(MLX_KEY_D, data);
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		move_player(MLX_KEY_D, data);
}
