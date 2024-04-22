/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:03:08 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 15:40:10 by demre            ###   ########.fr       */
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

void	initialise(char *filename, t_data *data)
{
	if (check_file_extension(filename) != SUCCESS)
		return (print_and_exit("Wrong file extension", 2, EXIT_FAILURE));
	if (get_data_from_file(filename, data) != SUCCESS)
		return (print_and_exit("Wrong map", 2, EXIT_FAILURE));
	//if (check_map(data) == FAILURE)
		//return (print_and_exit("Wrong map", 2, EXIT_FAILURE));
	data->mlx = mlx_init(2500, 1250, "cub3d", false);
	if (!data->mlx)
		printf("Error");
}
