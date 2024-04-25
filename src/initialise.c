/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:03:08 by demre             #+#    #+#             */
/*   Updated: 2024/04/25 14:16:29 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	data->window = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->window, 0, 0);
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
	if (!data->wall_no || !data->wall_so || !data->wall_we || !data->wall_ea)
		print_and_exit("Failed to initialise textures", 2, EXIT_FAILURE);
}

void	paint_sky_floor(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT / 2)
			mlx_put_pixel(data->window, x, y++, data->sky_color);
		/* while (y < HEIGHT)
			mlx_put_pixel(data->window, x, y++, data->floor_color); */
		x++;
	}
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
	data->minimap_tile_px = 32;
	data->player_speed = 3;
	if (check_file_extension(filename) != SUCCESS)
		return (print_and_exit("Wrong file extension", 2, EXIT_FAILURE));
	if (get_data_from_file(filename, data) != SUCCESS)
		return (print_and_exit("Wrong map", 2, EXIT_FAILURE));
	get_map_size(data);
	printf("data->col: %u, data->row: %u\n", data->col, data->row);
	initialise_mlx(data);
	initialise_texture(data);
	paint_sky_floor(data);
	data->minimap = mlx_new_image(data->mlx,
		data->col * data->minimap_tile_px, data->row * data->minimap_tile_px);
	mlx_image_to_window(data->mlx, data->minimap, 32, 32);
	paint_minimap(data);
}
