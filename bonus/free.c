/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:56:10 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 12:27:09 by blarger          ###   ########.fr       */
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

int	free_string_array_and_return(char **str_array, int to_return)
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
	return (to_return);
}

