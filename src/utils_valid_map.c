/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:19:16 by blarger           #+#    #+#             */
/*   Updated: 2024/04/23 11:19:58 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_horizontal_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != OUT && line[i] != WALL)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	line_has_valid_char(t_data *data, char *line)
{
	int	i;

	i = 0;
	if (line[0] != OUT && line[0] != WALL)
		return (FAILURE);
	while (line[i])
	{
		if (line[i] != OUT && line[i] != WALL
			&& line[i] != WEST && line[i] != EST
			&& line[i] != NORTH && line[i] != SOUTH
			&& line[i] != EMPTY)
			return (FAILURE);
		if (line[i] == WEST || line[i] == EST
			|| line[i] == NORTH || line[i] == SOUTH)
		{
			data->depart_position = line[i];
			data->map_departure_count++;
		}
		i++;
	}
	if ((line[i - 1] != OUT && line[i - 1] != WALL)
		|| data->map_departure_count > 1)
		return (FAILURE);
	return (SUCCESS);
}

int	valid_surrounded_wall(t_data *data, int i, int j)
{
	if (i + 1 < data->map_column && data->map[i + 1][j])
	{
		if (data->map[i + 1][j] != WALL && data->map[i + 1][j] != OUT)
			return (FAILURE);
	}
	if (i -1 > 0 && data->map[i - 1][j])
	{
		if (data->map[i - 1][j] != WALL && data->map[i - 1][j] != OUT)
			return (FAILURE);
	}
	if (data->map[i][j + 1])
	{
		if (data->map[i][j + 1] != WALL && data->map[i][j + 1] != OUT)
			return (FAILURE);
	}
	if (j - 1 > 0 && data->map[i][j - 1])
	{
		if (data->map[i][j - 1] != WALL && data->map[i][j - 1] != OUT)
			return (FAILURE);
	}
	return (SUCCESS);
}
