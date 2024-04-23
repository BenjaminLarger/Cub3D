#include "cub3d.h"

int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	if (check_horizontal_wall(data->map[0]) == FAILURE)
		return (FAILURE);
	while (data->map[i])
	{
		if (line_has_valid_char(data, data->map[i]) == FAILURE)
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

bool	splitted_map(char *map)
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

int	get_rid_of_empty_line(t_data *data, int fd, char *line, char **map)
{
	data->map_departure_count = 0;
	while (true)
	{
		line = ft_get_next_line(fd);
		if (!line)
			return (FAILURE);
		if (ft_strcmp(line, "\n"))
			break ;
		free(line);
	}
	*map = ft_strdup(line);
	free(line);
	return (SUCCESS);
}

int	load_map(t_data *data, int fd)
{
	char	*line;
	char	*map;

	line = NULL;
	map = NULL;
	if (get_rid_of_empty_line(data, fd, line, &map) == FAILURE)
		return (FAILURE);
	data->map_column = 0;
	while (line)
	{
		data->map_column++;
		line = ft_get_next_line(fd);
		map = ft_strjoin_free(map, line);
		free(line);
	}
	if (splitted_map(map) == true)
		return (FAILURE);
	data->map = ft_split(map, '\n');
	free(map);
	if (!data->map)
		return (FAILURE);
	print_map(data->map);
	if (check_map(data) == FAILURE)
		return (free_string_array_and_return(data->map, FAILURE));
	return (SUCCESS);
}
