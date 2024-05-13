/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:31:37 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 11:03:37 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	print_map(data->map);
	if (check_first_line(data->map[0], data->map[1]) == FAILURE)
		return (FAILURE);
	while (data->map[i])
	{
		if (line_has_valid_char(data, data->map[i], i) == FAILURE)
			return (FAILURE);
		j = 0;
		while (data->map[i][j])
		{
			if ((data->map[i][j] == OUT || data->map[i][j] == '2')
				&& valid_surrounded_wall(data, i, j) == FAILURE)
				return (FAILURE);
			j++;
		}
		i++;
	}
	if (check_last_line(data->map[i - 1], data->map[i - 2]) == FAILURE
		|| data->map_departure_count != 1)
		return (FAILURE);
	return (SUCCESS);
}

static int	fill_map_empty_space(t_data *data)
{
	int		i;
	int		j;
	int		max_column;

	max_column = get_max_column(data);
	i = 0;
	while (i < data->map_line)
	{
		j = 0;
		data->map[i] = line_filled_with_2(data->map[i], max_column);
		while (j < max_column)
		{
			if (data->map[i][j] == OUT)
				data->map[i][j] = '2';
			j++;
		}
		i++;
	}
	return (check_map(data));
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

static bool	invalid_char(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] == '2')
			return (true);
	}
	return (false);
}

static int	get_rid_of_empty_line(t_data *data, int fd, char **line, char **map)
{
	data->map_departure_count = 0;
	data->map_line = 0;
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
		data->map_line++;
		line = ft_get_next_line(fd);
		map = ft_strjoin_free(map, line);
		if (!map)
			print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
		free(line);
	}
	if (splitted_map(map) == true || invalid_char(map) == true)
		return (free(map), FAILURE);
	data->map = ft_split(map, '\n');
	free(map);
	if (!data->map)
		print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
	return (fill_map_empty_space(data));
}
