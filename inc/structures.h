/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:35 by demre             #+#    #+#             */
/*   Updated: 2024/04/23 10:54:24 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// ----------- TEXTURES
typedef struct s_textures
{
	mlx_texture_t	*ceiling;
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
}				t_textures;

// ----------- IMAGES
typedef struct s_images
{
	mlx_image_t		*ceiling;
	mlx_image_t		*floor;
	mlx_image_t		*wall;
}			t_images;

// ----------- MAIN
typedef struct s_data
{
	mlx_t			*mlx;
	xpm_t			*tex_ceiling;
	xpm_t			*tex_floor;
	xpm_t			*tex_wall;
	xpm_t			*tex_player;
	t_textures		*texture;
	t_images		*image;
	int				map_column;
	int				map_departure_count;
	char			depart_position;
	char			**map;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	char			*floor_color;
	char			*ceiling_color;
	unsigned int	tile_width;
	unsigned int	tile_height;
	unsigned int	col;
	unsigned int	row;
	unsigned int	window_width;
	unsigned int	window_height;
	int				player_x;
	int				player_y;
}	t_data;


// ----------- Identifier flags
typedef struct s_id_flags
{
	int		id_no;
	int		id_so;
	int		id_we;
	int		id_ea;
	int		id_f;
	int		id_c;
}			t_id_flags;

#endif
