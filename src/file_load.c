/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:02 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 18:10:51 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_data_from_file(char *filename, t_data *data)
{
	int		n_elements;
	int		fd;

	n_elements = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (FAILURE);
	load_elements(&n_elements, data, fd);
	printf("data->north_path: '%s', data->south_path: '%s', data->west_path: '%s', data->east_path: '%s', data->floor_color: '%s', data->ceiling_color: '%s'\n", data->north_path, data->south_path, data->west_path, data->east_path, data->floor_color, data->ceiling_color);
	if (n_elements != 6)
		return (FAILURE);

	//load_map(data);

	return (SUCCESS);
}
