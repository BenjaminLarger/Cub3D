#include "cub3d.h"

static int	count_map_lines(int i, char **split_line)
{
	int	map_lines;

	map_lines = 0;
	while (split_line[i])
	{
		map_lines++;
		i++;
	}
	return (map_lines);
}

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

int	line_is_valid(char *line)
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

int	load_map(t_data *data, int i, char **split_line)
{
	int	map_index;

	while (split_line[i] && !ft_strcmp(split_line[i], "\n"))
		i++;
	if (check_horizontal_wall(split_line[i]) == FAILURE)
		return (FAILURE);
	data->map = (char **)malloc(sizeof(char *) * count_map_lines(i, split_line));
	if (!data->map)
		return (FAILURE);//malloc failure
	map_index = 0;
	while (split_line[i])
	{
		data->map[map_index] = ft_strdup(split_line[i]);
		if (!data->map || line_is_valid(slpit_line[i]) == FAILURE)
			return (free_n_string_array_and_return(data->map, i), FAILURE);
		i++;
	}
	if (check_horizontal_wall(split_line[i - 1]) == FAILURE)
		return (free_string_array_and_return(data->map));
	if (valid_wall(data->map) == FAILURE)
		return (free_string_array_and_return(data->map));
	return (SUCCESS);
}
