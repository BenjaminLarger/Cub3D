/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:02 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 15:46:44 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
