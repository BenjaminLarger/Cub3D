/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fill_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:37:30 by blarger           #+#    #+#             */
/*   Updated: 2024/04/25 16:38:06 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_max_column(t_data *data)
{
	int	i;
	int	j;
	int	max_column;

	max_column = 0;
	i = 0;
	while (i < data->map_line)
	{
		j = 0;
		while (data->map[i][j])
			j++;
		if (j > max_column)
			max_column = j;
		i++;
	}
	return (max_column);
}

char	*line_filled_with_2(char *line, int max_column)
{
	int		i;
	char	*newline;

	i = 0;
	newline = (char *)malloc(sizeof(char) * max_column + 1);
	if (!newline)
		return (print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE), NULL);
	while (line[i])
	{
		newline[i] = line[i];
		i++;
	}
	while (i < max_column)
	{
		newline[i] = '2';
		i++;
	}
	newline[i] = '\0';
	free(line);
	return (newline);
}