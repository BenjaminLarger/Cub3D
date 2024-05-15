/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:34:29 by blarger           #+#    #+#             */
/*   Updated: 2024/05/15 11:07:52 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	get_col(char **map)
{
	int	i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

static int	doors_are_too_close(t_data *data, int y, int x)
{
	int	ya;
	int	xa;

	data->col = get_col(data->map);
	ya = -2;
	if (y + ya < 1)
		ya = 1 - y;
	while (ya <= 2 && (y + ya) < data->map_line - 1)
	{
		xa = -2;
		if (x + xa < 1)
			xa = 1 - x;
		while (xa <= 2 && (xa + x) < (int)data->col - 1)
		{
			if (ya == 0 && xa == 0)
				xa++;
			if (data->map[y + ya][x + xa] == DOOR_CLOSED)
				return (FAILURE);
			xa++;
		}
		ya++;
	}
	return (SUCCESS);
}

int	doors_input(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == DOOR_CLOSED)
			{
				if (doors_are_too_close(data, i, j) == FAILURE)
					return (FAILURE);
			}
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
