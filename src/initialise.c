/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:03:08 by demre             #+#    #+#             */
/*   Updated: 2024/04/23 15:31:53 by demre            ###   ########.fr       */
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

	for (uint32_t x = 0; x < WIDTH; ++x)
		{
			for (uint32_t y = 0; y < HEIGHT; ++y)
			{
				mlx_put_pixel(data->window, x, y, 0x000000FF);
			}
		}
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

	
	data->test = mlx_texture_to_image(data->mlx, data->wall_no);
	mlx_image_to_window(data->mlx, data->test, 0, 0);
}

void	initialise(char *filename, t_data *data)
{
	if (check_file_extension(filename) != SUCCESS)
		return (print_and_exit("Wrong file extension", 2, EXIT_FAILURE));
	if (get_data_from_file(filename, data) != SUCCESS)
		return (print_and_exit("Wrong map", 2, EXIT_FAILURE));
	initialise_mlx(data);
	initialise_texture(data);
}
