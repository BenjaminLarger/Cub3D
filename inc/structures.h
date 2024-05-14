/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:35 by demre             #+#    #+#             */
/*   Updated: 2024/05/14 18:15:11 by demre            ###   ########.fr       */
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
	unsigned int	col;
	unsigned int	row;
	double			player_x;
	double			player_y;
	double			pdx;
	double			pdy;
	double			player_angle;
	double			player_speed;
	double			angle_step;
	double			view_angle;
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
	uint32_t		r;
	uint32_t		g;
	uint32_t		b;
	int				index;
	unsigned int	num;
}			t_rgb;

// ----------- paint_field_of_view

typedef struct s_pfv
{
	double	ray_length;
	double	ray_length_n1;
	double	ray_length_n2;
	double	ray_length_to_door;
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
	double	wall_x_n1;
	double	wall_y_n1;
}			t_pfv;

// ----------- Ray-Casting

typedef struct s_map
{
	double	xa;
	double	ya;
	double	new_x;
	double	new_y;
	double	old_x;
	double	old_y;
	double	len;
	double	m;
	double	b;
}			t_map;

// ----------- Corner identifier

typedef struct s_corner
{
	bool	south_west_blocked;
	bool	south_est_blocked;
	bool	north_west_blocked;
	bool	north_est_blocked;
}			t_corner;

#endif
