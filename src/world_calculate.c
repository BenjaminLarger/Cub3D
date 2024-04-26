/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:58 by demre             #+#    #+#             */
/*   Updated: 2024/04/26 16:45:53 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calculate_col_height(t_data *data, t_pfv pfv)
{
	double	calculated_h;

	(void)data;
	calculated_h = 1000 / pfv.ray_length;
	return (calculated_h);
}
