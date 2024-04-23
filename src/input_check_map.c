#include "cub3d.h"

/* static int	count_map_lines(int i, char **split_line)
{
	int	map_lines;

	map_lines = 0;
	while (split_line[i])
	{
		map_lines++;
		i++;
	}
	return (map_lines);
} */

int	check_horizontal_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != EMPTY && line[i] != WALL)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	line_has_valid_char(char *line)
{
	int	i;

	i = 0;
	if (line[0] != EMPTY && line[0] != WALL)
		return (FAILURE);
	while (line[i])
	{
		if (line[i] != EMPTY && line[i] != WALL
			&& line[i] != WEST && line[i] != EST
			&& line[i] != NORTH && line[i] != SOUTH)
			return (FAILURE);
		i++;
	}
	if (line[i - 1] != EMPTY && line[i - 1] != WALL)
		return (FAILURE);
	return (SUCCESS);
}

int	valid_surrounded_wall(t_data *data, int i, int j)
{
	if (data->map[i + 1][j] != WALL && data->map[i + 1][j] != EMPTY)
		return (FAILURE);
	if (data->map[i - 1][j] != WALL && data->map[i - 1][j] != EMPTY)
		return (FAILURE);
	if (data->map[i][j + 1] != WALL && data->map[i][j + 1] != EMPTY)
		return (FAILURE);
	if (data->map[i][j - 1] != WALL && data->map[i][j - 1] != EMPTY)
		return (FAILURE);
	return (SUCCESS);
}

int	check_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_horizontal_wall(data->map[0]) == FAILURE)
		return (FAILURE);
	while (data->map[i])
	{
		if (line_has_valid_char(data->map[i]) == FAILURE)
			return (FAILURE);
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == EMPTY)
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

int	load_map(t_data *data, int fd)
{
	char	*line;
	char	*map;

	while (true)
	{
		line = ft_get_next_line(fd);
		if (ft_strcmp(line, "\n"))
			break ;
		free(line);
	}
	free(line);
	map = NULL;
	while (line)
	{
		line = ft_get_next_line(fd);
		map = ft_strjoin_free(map, line);
		free(line);
	}
	data->map = ft_split(map, '\n');
	if (!data->map)
		return (FAILURE);
	if (check_map(data) == FAILURE)
		return (free_string_array_and_return(data->map, FAILURE));
	return (SUCCESS);
}
