/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:19:16 by blarger           #+#    #+#             */
/*   Updated: 2024/05/14 12:13:07 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_first_line(char *line, char *scd_line)
{
	int	i;

	i = 0;
	if (line[0] == WALL && line[1] == '2' && scd_line[0] == '2')
		return (FAILURE);
	while (line[i])
	{
		if (line[i] != OUT && line[i] != WALL && line[i] != '2'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E'
			&& line[i] != 'N')
		{
			return (FAILURE);
		}
		if (i != 0 && line[i + 1] != '\0' && line[i - 1] == '2'
			&& line[i] == WALL && line[i + 1] == '2' && scd_line[i] == '2')
			return (FAILURE);
		if (line[i + 1] == '\0' && line[i] == WALL && line[i - 1] == '2'
			&& scd_line[i] == '2')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	check_last_line(char *line, char *last_line)
{
	int	i;

	i = 0;
	if (line[0] == WALL && line[1] == '2' && last_line[0] == '2')
		return (FAILURE);
	while (line[i])
	{
		if (line[i] != OUT && line[i] != WALL && line[i] != '2'
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E'
			&& line[i] != 'N')
		{
			return (FAILURE);
		}
		if (i != 0 && line[i + 1] != '\0' && line[i - 1] == '2'
			&& line[i] == WALL && line[i + 1] == '2' && last_line[i] == '2')
			return (FAILURE);
		if (line[i + 1] == '\0' && line[i] == WALL && line[i - 1] == '2'
			&& last_line[i] == '2')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

static void	player_init_attributes(t_data *data, char angle_start, int y, int x)
{
	data->depart_position = angle_start;
	if (angle_start == EST)
		data->player_angle = 0.0;
	else if (angle_start == SOUTH)
		data->player_angle = M_PI_2;
	else if (angle_start == WEST)
		data->player_angle = M_PI;
	else if (angle_start == NORTH)
		data->player_angle = M_PI_2 * 3;
	data->player_x = x + 0.5;
	data->player_y = y + 0.5;
	data->map_departure_count++;
}

int	line_has_valid_char(t_data *data, char *line, int y)
{
	int	i;

	i = 0;
	if (line[0] != OUT && line[0] != WALL && line[0] != '2')
		return (FAILURE);
	while (line[i])
	{
		if (line[i] != OUT && line[i] != WALL
			&& line[i] != WEST && line[i] != EST
			&& line[i] != NORTH && line[i] != SOUTH
			&& line[i] != FLOOR && line[i] != '2')
			return (FAILURE);
		if (line[i] == WEST || line[i] == EST
			|| line[i] == NORTH || line[i] == SOUTH)
			player_init_attributes(data, line[i], y, i);
		i++;
	}
	if ((line[i - 1] != OUT && line[i - 1] != WALL && line[i - 1] != '2')
		|| data->map_departure_count > 1)
		return (FAILURE);
	return (SUCCESS);
}

int	valid_surrounded_wall(t_data *data, int i, int j)
{
	if (i + 1 < data->map_line && data->map[i + 1][j])
	{
		if (data->map[i + 1][j] != WALL && data->map[i + 1][j] != OUT
			&& data->map[i + 1][j] != '2')
			return (FAILURE);
	}
	if (i - 1 > 0 && data->map[i - 1][j])
	{
		if (data->map[i - 1][j] != WALL && data->map[i - 1][j] != OUT
			&& data->map[i - 1][j] != '2')
			return (FAILURE);
	}
	if (data->map[i][j + 1])
	{
		if (data->map[i][j + 1] != WALL && data->map[i][j + 1] != OUT
			&& data->map[i][j + 1] != '2')
			return (FAILURE);
	}
	if (j - 1 > 0 && data->map[i][j - 1])
	{
		if (data->map[i][j - 1] != WALL && data->map[i][j - 1] != OUT
			&& data->map[i][j - 1] != '2')
			return (FAILURE);
	}
	return (SUCCESS);
}
