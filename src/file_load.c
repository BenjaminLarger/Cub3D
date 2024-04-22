/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_load.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:02 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 16:34:12 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_identifiers(int *identifiers_loaded, char *filename, t_data *data)
{
	int		file_descriptor;
	char	*line;
	char	**split_line;

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (FAILURE);
	while (*identifiers_loaded < 6)
	{
		line = ft_get_next_line(file_descriptor);
		if (!line)
			print_and_exit("Wrong data in file", 2, EXIT_FAILURE);
		split_line = ft_split(line, ' ');
		if (!split_line) // free line
			print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
		print_array(split_line, "Splitting line:");
		if (ft_strcmp(split_line[0], "\n") == 0)
		{
			printf("split_line[0] is a newline\n");
			free(line);
			free_string_array(split_line);
			continue ;
		}
		if (split_line[2] != NULL)
			print_and_exit("Wrong information on file line", 2, EXIT_FAILURE);
		if (ft_strcmp(split_line[0], "NO") == 0)
			data->north_path = ft_strdup(split_line[1]);
		else if (ft_strcmp(split_line[0], "SO") == 0)
			data->south_path = ft_strdup(split_line[1]);
		else if (ft_strcmp(split_line[0], "WE") == 0)
			data->west_path = ft_strdup(split_line[1]);
		else if (ft_strcmp(split_line[0], "EA") == 0)
			data->east_path = ft_strdup(split_line[1]);
		else if (ft_strcmp(split_line[0], "F") == 0)
			data->floor_color = ft_strdup(split_line[1]);
		else if (ft_strcmp(split_line[0], "C") == 0)
			data->ceiling_color = ft_strdup(split_line[1]);
		*identifiers_loaded += 1;
		free(line);
		free_string_array(split_line);
	}
	if (*identifiers_loaded == 6)
		return (SUCCESS);
	return (FAILURE);
}

int	get_data_from_file(char *filename, t_data *data)
{
	int		identifiers_loaded;

	identifiers_loaded = 0;

	if (load_identifiers(&identifiers_loaded, filename, data) != SUCCESS)
		return (FAILURE);
	// get textures

	// get floor and ceiling colors

	// get map to data->map
//	if ( identifiers_loaded == 6 )
	//load_map(data);

	return (SUCCESS);
}
