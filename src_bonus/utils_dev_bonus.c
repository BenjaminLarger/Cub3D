/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:16:07 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 15:48:16 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	check_leaks(void)
{
	system("leaks cub3D");
}

void	display_fps(void)
{
	static long long	frameCount = 0;
	static double		startTime = 0;
	double				elapsedTime;
	double				fps;

	frameCount++;
	elapsedTime = mlx_get_time() - startTime;
	fps = frameCount / elapsedTime;
	if (elapsedTime >= 1.0)
	{
		printf("FPS:	 %.0f\n", fps);
		frameCount = 0;
		startTime = mlx_get_time();
	}
}
