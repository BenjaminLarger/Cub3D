/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:16:07 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 16:20:31 by demre            ###   ########.fr       */
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
