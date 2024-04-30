/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:35 by demre             #+#    #+#             */
/*   Updated: 2024/04/30 15:12:31 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// ----------- MAIN

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*world;
	mlx_image_t		*buffer_world;
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
	double	angle_step;
	double	view_angle;
	double			calculated_h;
	double			display_h;
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
	double	wall_x;
	double	wall_y;
}			t_pfv;

// ----------- find next edge
typedef struct s_edge
{
	double	cur_x;
	double	cur_y;
	double	new_x1;
	double	new_y1;
	double	new_x2;
	double	new_y2;
	double	distance_to_wall;
	double	ray_x;
	double	ray_y;
	double	ray_dx;
	double	ray_dy;
	double	distance_to_next_x_edge;
	double	distance_to_next_y_edge;
	double	m;
	double	b;
}			t_edge;

#endif
