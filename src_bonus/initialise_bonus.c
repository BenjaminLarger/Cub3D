/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:03:08 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 14:32:52 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	check_file_extension(char *filename)
{
	char	*file_extension;

	file_extension = ft_strrchr(filename, '.');
	if (!file_extension
		|| ft_strlen(file_extension) != 4
		|| ft_strncmp(file_extension, ".cub", ft_strlen(file_extension)) != 0)
		return (FAILURE);
	return (SUCCESS);
}

static void	initialise_mlx(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!data->mlx)
		print_and_exit("Failed to initialise graphic engine", 2, EXIT_FAILURE);
}

static void	initialise_texture(t_data *data)
{
	data->wall_no = mlx_load_png(data->north_path);
	data->wall_so = mlx_load_png(data->south_path);
	data->wall_we = mlx_load_png(data->west_path);
	data->wall_ea = mlx_load_png(data->east_path);
	free(data->north_path);
	free(data->south_path);
	free(data->west_path);
	free(data->east_path);
	data->sprite_texture1 = mlx_load_png("./texture/flame1.png");
	data->sprite_texture2 = mlx_load_png("./texture/flame2.png");
	data->sprite_texture3 = mlx_load_png("./texture/flame3.png");
	data->sprite_texture4 = mlx_load_png("./texture/flame4.png");
	data->door_close = mlx_load_png("./texture/forest_door_closed.png");
	if (!data->wall_no || !data->wall_so || !data->wall_we || !data->wall_ea
		|| !data->sprite_texture1 || !data->sprite_texture2
		|| !data->sprite_texture3 || !data->sprite_texture4
		|| !data->door_close)
		print_and_exit("Failed to initialise textures", 2, EXIT_FAILURE);
}

void	get_map_size(t_data *data)
{
	unsigned int	temp_col;

	data->col = 0;
	data->row = 0;
	temp_col = 0;
	while (data->map[data->row])
	{
		temp_col = 0;
		while (data->map[data->row][temp_col])
			temp_col++;
		if (temp_col > data->col)
			data->col = temp_col;
		data->row++;
	}
}

void	initialise(char *filename, t_data *data)
{
	data->prev_mouse_x = -1;
	data->minimap_tile_px = 16;
	data->display_minimap = TRUE;
	data->player_speed = 1;
	data->loop = 0;
	data->player_can_open_door = false;
	data->view_angle = PLAYER_FOV * (M_PI / 180);
	data->angle_step = PLAYER_FOV * (M_PI / 180) / NUM_OF_RAYS;
	if (check_file_extension(filename) != SUCCESS)
		return (print_and_exit("Wrong file extension", 2, EXIT_FAILURE));
	if (get_data_from_file(filename, data) != SUCCESS)
		return (print_and_exit("Wrong map", 2, EXIT_FAILURE));
	get_map_size(data);
	initialise_mlx(data);
	initialise_texture(data);
	initialise_world(data);
	initialise_minimap(data);
	initialise_sprite(data);
	paint_world(data);
	paint_minimap(data);
	paint_sprite(data);
	if (data->paint_in_render == TRUE) // to delete
		mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
}
