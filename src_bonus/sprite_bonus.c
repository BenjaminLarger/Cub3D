/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:11:39 by demre             #+#    #+#             */
/*   Updated: 2024/05/13 16:40:44 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/* uint32_t	pack_rgba(uint8_t pixels[4])
{
	uint32_t	color;

	color = 0;
	color |= ((uint32_t)pixels[0] << 24);
	color |= ((uint32_t)pixels[1] << 16);
	color |= ((uint32_t)pixels[2] << 8);
	color |= pixels[3];
	return (color);
}

uint32_t	get_sp_px_color(unsigned int sp_x, unsigned int sp_y,
	mlx_texture_t *texture)
{
	uint32_t		index;
	uint8_t			rgba[4];
	unsigned int	i;

	if (!texture || !texture->pixels)
		return (0);
	index = (sp_x + sp_y) * texture->bytes_per_pixel;
	i = 0;
	while (i < 4)
	{
		rgba[i] = texture->pixels[index + i];
		i++;
	}
	return (pack_rgba(rgba));
} */

void	paint_sprite(t_data *data)
{
	unsigned int	sp_x;
	unsigned int	sp_y;

	sp_x = 0;
	sp_y = 0;

	while (sp_x < 125)
	{
		sp_y = 0;
		while (sp_y < 500)
		{
			mlx_put_pixel(data->sprite, sp_x, sp_y, 0);
//				get_sp_px_color(sp_x, sp_y, data->sprite_texture));
			sp_y++;
		}
		sp_x++;
	}
}

void	initialise_sprite(t_data *data)
{
	data->sprite = mlx_new_image(data->mlx, 125, 500);
	if (!data->sprite
		|| mlx_image_to_window(data->mlx, data->sprite, 960, 640) < 0)
		print_and_exit("Failed to initialise image", 2, EXIT_FAILURE);
}
