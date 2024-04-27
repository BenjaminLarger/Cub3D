/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/27 15:56:46 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_col_height(t_data *data, t_pfv pfv)
{
	double	calculated_h;

	(void)data;
	calculated_h = WIDTH / pfv.ray_length;
	if (calculated_h > HEIGHT)
		calculated_h = HEIGHT;
	return (calculated_h);
}
