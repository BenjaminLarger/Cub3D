/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:35 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 14:24:54 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_data
{
	mlx_t			*mlx;
	xpm_t			*tex_ceiling;
	xpm_t			*tex_floor;
	xpm_t			*tex_wall;
	xpm_t			*tex_player;
	mlx_image_t		*img_ceiling;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_wall;
	unsigned int	tile_width;
	unsigned int	tile_height;
	unsigned int	col;
	unsigned int	row;
	unsigned int	window_width;
	unsigned int	window_height;
	char			**map;
	int				player_x;
	int				player_y;
}	t_data;

#endif
