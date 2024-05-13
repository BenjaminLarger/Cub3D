/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:11:39 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 17:32:00 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

uint32_t	get_sp_px_color(unsigned int sp_x, unsigned int sp_y,
	mlx_texture_t *texture)
{
	uint32_t		index;
	uint8_t			rgba[4];
	unsigned int	i;

	if (!texture || !texture->pixels)
		return (0);
	index = (sp_y * texture->width + sp_x) * texture->bytes_per_pixel;
	i = 0;
	while (i < 4)
	{
		rgba[i] = texture->pixels[index + i];
		i++;
	}
	return (pack_rgba(rgba));
}

void	paint_sprite(t_data *data)
{
	unsigned int	sp_x;
	unsigned int	sp_y;
	mlx_texture_t	*temp_texture;

	sp_x = 0;
	sp_y = 0;
	if (data->loop < 2)
		temp_texture = data->sprite_texture1;
	else if (data->loop >= 2 && data->loop < 4)
		temp_texture = data->sprite_texture2;
	else if (data->loop >= 4 && data->loop < 6)
		temp_texture = data->sprite_texture3;
	else if (data->loop >= 6)
		temp_texture = data->sprite_texture4;
	while (sp_y < 400)
	{
		sp_x = 0;
		while (sp_x < 125)
		{
			mlx_put_pixel(data->sprite, sp_x, sp_y,
				get_sp_px_color(sp_x, sp_y, temp_texture));
			sp_x++;
		}
		sp_y++;
	}
}

void	initialise_sprite(t_data *data)
{
	data->sprite = mlx_new_image(data->mlx, 125, 500);
	if (!data->sprite
		|| mlx_image_to_window(data->mlx, data->sprite, 1250, HEIGHT - 400) < 0)
		print_and_exit("Failed to initialise image", 2, EXIT_FAILURE);
}
