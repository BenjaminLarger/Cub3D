/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:35 by demre             #+#    #+#             */
/*   Updated: 2024/04/26 17:20:52 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// ----------- MAIN

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*world;
	mlx_image_t		*minimap;
	mlx_texture_t	*wall_no;
	mlx_texture_t	*wall_so;
	mlx_texture_t	*wall_we;
	mlx_texture_t	*wall_ea;
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
	unsigned int	col;
	unsigned int	row;
	double			player_x;
	double			player_y;
	double			pdx;//player direction x
	double			pdy;//player direction y
	double			player_angle;
	double			player_speed;
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

// ----------- paint_field_of_view

typedef struct s_pfv
{
	double	ray_length;
	double	endX;
	double	endY;
	int		n_pixels_to_draw;
	int		total_pixels_to_draw;
	double	pixelX;
	double	pixelY;
	double	view_angle;
	double	angle_step;
	double	ray_angle;
	int		i;
}			t_pfv;

#endif
