/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:30:35 by demre             #+#    #+#             */
/*   Updated: 2024/05/14 18:01:15 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

// ----------- MAIN

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*world;
	mlx_image_t		*buffer_world;
	mlx_image_t		*minimap;
	mlx_image_t		*sprite;
	mlx_texture_t	*wall_no;
	mlx_texture_t	*wall_so;
	mlx_texture_t	*wall_we;
	mlx_texture_t	*wall_ea;
	mlx_texture_t	*door_close;
	mlx_texture_t	*door_open;
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
	unsigned int	minimap_tile_px; // minimap
	unsigned int	mm_max_width_px; // minimap
	unsigned int	mm_max_height_px; // minimap
	double			mm_max_col; // minimap
	double			mm_max_row; // minimap
	double			mm_row_start_px; // minimap
	double			mm_row_end_px; // minimap
	double			mm_col_start_px; // minimap
	double			mm_col_end_px; // minimap
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
	int paint_in_render; // to delete
	int				loop;
	double			prev_mouse_x;
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
	char	obstacle;
	int		obs_x;
	int		obs_y;
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

#endif
