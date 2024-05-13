/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:02 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 12:26:13 by blarger          ###   ########.fr       */
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
	if (n_elements != 6)
		return (FAILURE);
	if (load_map(data, fd) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
