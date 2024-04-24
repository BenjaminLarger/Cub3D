/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:31:37 by demre             #+#    #+#             */
/*   Updated: 2024/04/24 11:53:59 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (check_horizontal_wall(data->map[0]) == FAILURE)
		return (FAILURE);
	while (data->map[i])
	{
		if (line_has_valid_char(data, data->map[i], i) == FAILURE)
			return (FAILURE);
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == OUT)
			{
				if (valid_surrounded_wall(data, i, j) == FAILURE)
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	if (check_horizontal_wall(data->map[i - 1]) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static bool	splitted_map(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n')
		{
			i++;
			while (map[i] != '\0' && map[i] == ' ')
				i++;
			if (map[i] == '\n')
			{
				free(map);
				return (true);
			}
		}
		if (map[i] != '\0')
			i++;
	}
	return (false);
}

static int	get_rid_of_empty_line(t_data *data, int fd, char **line, char **map)
{
	data->map_departure_count = 0;
	data->map_column = 0;
	while (true)
	{
		*line = ft_get_next_line(fd);
		if (!(*line))
			return (FAILURE);
		if (ft_strcmp(*line, "\n"))
			break ;
		free(*line);
	}
	*map = ft_strdup(*line);
	free(*line);
	if (!(*map))
		return (FAILURE);
	return (SUCCESS);
}

int	load_map(t_data *data, int fd)
{
	char	*line;
	char	*map;

	line = NULL;
	map = NULL;
	if (get_rid_of_empty_line(data, fd, &line, &map) == FAILURE)
		print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
	while (line)
	{
		data->map_column++;
		line = ft_get_next_line(fd);
		map = ft_strjoin_free(map, line);
		if (!map)
			print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
		free(line);
	}
	if (splitted_map(map) == true)
		return (FAILURE);
	data->map = ft_split(map, '\n');
	free(map);
	if (!data->map)
		print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
	print_map(data->map);
	return (check_map(data));
}
