/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:56:10 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 14:56:27 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_string_array(char **str_array)
{
	int	i;

	i = 0;
	if (str_array)
	{
		while (str_array[i])
		{
			free(str_array[i]);
			str_array[i] = NULL;
			i++;
		}
	}
	free(str_array);
}

void	free_n_string_array(char **str_array, int n)
{
	while (n > 0)
	{
		free(str_array[n - 1]);
		str_array[n - 1] = NULL;
		n--;
	}
	free(str_array);
}
