/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:55:53 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 14:56:31 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_game(t_data *data)
{
//	mlx_delete_xpm42(data->tex_wall);
	mlx_terminate(data->mlx);
//	free_map(data->map, data->row);
}
