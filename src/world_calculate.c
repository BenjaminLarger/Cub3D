/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_calculate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:17:58 by demre             #+#    #+#             */
/*   Updated: 2024/05/11 13:48:09 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_col_height(t_data *data, t_pfv pfv)
{
	data->calculated_h = WIDTH / pfv.ray_length;
	if (data->calculated_h > HEIGHT)
		data->display_h = HEIGHT;
	else
		data->display_h = data->calculated_h;
}
