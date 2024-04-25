/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:35 by demre             #+#    #+#             */
/*   Updated: 2024/04/25 08:56:32 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// ----------- TEXTURES
typedef struct s_textures
{
	mlx_texture_t	*sky;
	mlx_texture_t	*floor;
}			t_textures;

// ----------- IMAGES
typedef struct s_images
{
	mlx_image_t		*sky;
	mlx_image_t		*floor;
	mlx_image_t		*wall_no;
	mlx_image_t		*wall_so;
	mlx_image_t		*wall_we;
	mlx_image_t		*wall_ea;
}			t_images;

// ----------- MAIN
typedef struct s_data
{
	mlx_t			*mlx;
	t_textures		*texture;
	t_images		*image;
	mlx_image_t		*window;
	mlx_image_t		*minimap;
	mlx_texture_t	*wall_no;
	mlx_texture_t	*wall_so;
	mlx_texture_t	*wall_we;
	mlx_texture_t	*wall_ea;
	mlx_image_t		*test;
	int				map_line;
	int				map_departure_count;
	char			depart_position;
	char			**map;
	char			*north_path;
	char			*south_path;
	char			*west_path;
	char			*east_path;
	unsigned int	floor_color;
	unsigned int	sky_color;
	unsigned int	minimap_tile_px;
	unsigned int	col; // total number of col in map
	unsigned int	row; // total number of row in map
	unsigned int	window_width; // not used
	unsigned int	window_height; // not used
	double			player_x;
	double			player_y;
	double			pdx;//player direction x
	double			pdy;//player direction y
	double 			player_angle;
	double 			player_speed;
}			t_data;

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

// ----------- RGB to hex conversion
typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
	int				index;
	unsigned int	num;
}			t_rgb;

#endif
