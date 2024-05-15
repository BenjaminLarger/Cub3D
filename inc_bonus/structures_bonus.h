/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:35 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 21:20:59 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

// ----------- MAIN

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*world;
	mlx_image_t		*minimap;
	mlx_image_t		*sprite;
	mlx_texture_t	*wall_no;
	mlx_texture_t	*wall_so;
	mlx_texture_t	*wall_we;
	mlx_texture_t	*wall_ea;
	mlx_texture_t	*door_close;
	mlx_texture_t	*sprite_texture1;
	mlx_texture_t	*sprite_texture2;
	mlx_texture_t	*sprite_texture3;
	mlx_texture_t	*sprite_texture4;
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
	int				display_minimap;
	unsigned int	minimap_tile_px;
	unsigned int	mm_max_width_px;
	unsigned int	mm_max_height_px;
	double			mm_max_col;
	double			mm_max_row;
	double			mm_row_start_px;
	double			mm_row_end_px;
	double			mm_col_start_px;
	double			mm_col_end_px;
	unsigned int	col;
	unsigned int	row;
	double			player_x;
	double			player_y;
	double			player_angle;
	double			player_speed;
	double			angle_step;
	double			view_angle;
	int paint_in_render; // to delete
	int				loop;
	bool			player_can_open_door;
	bool			door_is_open;
	double			x_door_op;
	double			y_door_op;
	double			prev_mouse_x;
	bool			move_in_corner;//may have to delete
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
	double	ray_angle;
	int		i;
	double	calculated_h;
	double	display_h;
	double	wall_x;
	double	wall_y;
	double	wall_x_n1;
	double	wall_y_n1;
	char	obstacle;
	int		obs_x;
	int		obs_y;
	bool	door_found;
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

typedef struct s_corner
{
	bool	south_west_blocked;
	bool	south_est_blocked;
	bool	north_west_blocked;
	bool	north_est_blocked;
}			t_corner;

// ----------- player icon minimap

typedef struct s_mm_plyr
{
	unsigned int	center_x;
	unsigned int	center_y;
	double			radius;
	double			dx;
	double			dy;
	int				x;
	int				y;
	int				steps;
	double			x_inc;
	double			y_inc;
}			t_mm_plyr;

#endif
