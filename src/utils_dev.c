/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:16:07 by demre             #+#    #+#             */
/*   Updated: 2024/04/23 09:41:26 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Print a string array to terminal
*/
void	print_array(char **array, char *message)
{
	int	i;

	if (message && ft_strlen(message) > 0)
		fprintf(stderr, "%s\n", message);

	i = 0;
	while (array[i])
	{
		dprintf(2, "array[%d]: '%s'\n", i, array[i]);
		i++;
	}
	dprintf(2, "array[%d]: '%s'\n", i, array[i]); // check NULL
}

void	print_map(char **map)
{
	int	i;
	int	j;

	printf("check map\n");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
