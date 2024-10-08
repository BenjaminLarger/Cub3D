/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:24 by demre             #+#    #+#             */
/*   Updated: 2024/05/16 12:56:37 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "MLX42/MLX42.h"
# include "libft.h"
# include "errors_bonus.h"
# include "structures_bonus.h"

// Boolean

# define FALSE 0
# define TRUE 1
# define FAILURE 1
# define SUCCESS 0

// Map input

# define OUT ' '
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EST 'E'
# define WEST 'W'
# define FLOOR '0'
# define DOOR_CLOSED 'C'
# define DOOR_OPEN 'O'

// Windows param

# define WIDTH 1920
# define HEIGHT 1280
# define PLAYER_FOV 60
# define NUM_OF_RAYS 1920
# define SENSIBILITY 0.01

// Ray-Casting

# define INC 0.000000001
# define INC2 0.000000000000001
# define DESINC 0.999999999999999

// Slide on wall

# define FORWARD "Forward"
# define BACKWARD "Backward"
// HW = Horizontal wall // VW Vertical wall
# define HW 1
# define VW 2

// Initialisation

void			initialise(char *filename, t_data *data);
int				get_data_from_file(char *filename, t_data *data);
void			load_elements(int *n_elements, t_data *data, int fd);
unsigned int	rgb_to_hex(char *rgb_str);
int				load_map(t_data *data, int fd);
void			initialise_world(t_data *data);

// Minimap

void			paint_minimap(t_data *data);
void			paint_mm_player(t_data *data);
void			initialise_minimap(t_data *data);

// World

void			paint_world(t_data *data);
void			paint_walls(t_data *data);
uint32_t		pack_rgba(uint8_t pixels[4]);
void			calculate_col_height(t_pfv *pfv);
void			get_obstacle_type_on_right_side(t_data *data, t_pfv *pfv);
void			get_obstacle_type_on_left_side(t_data *data, t_pfv *pfv);
void			update_wall_data(t_data *data, t_pfv *pfv);
void			update_prev_rays_distance_data(t_pfv *pfv);

// User input

void			move_forward(t_data *data);
void			move_backward(t_data *data);
void			move_right(t_data *data);
void			move_left(t_data *data);
void			player_input(void *param);
void			minimap_control(mlx_key_data_t keydata, void *param);
bool			player_can_move(t_data *data, double end_x, double end_y);
bool			move_in_corner(t_data *data, double x, double y);
void			mouse_control(double xpos, double ypos, void *param);
int				get_next_wall(t_data *data, double angle);
void			player_slide_on_wall(t_data *data, char *direction,
					double end_x, double end_y);

// Ray casting

void			get_slope_info(t_data *data, t_map *map, double ray_angle);
double			find_vertical_wall_loop(t_data *data, t_map *map,
					double ray_angle);
double			find_horizontal_wall_loop(t_data *data, t_map *map,
					double ray_angle);
void			adjust_extrem_value(t_map *map, t_data *data);
double			get_wall_distance(t_data *data, double ray_angle);
double			find_vertical_intersection(t_data *data, double ray_angle);
double			find_horizontal_intersection(t_data *data, double ray_angle);

// Sprite

void			initialise_sprite(t_data *data);
void			paint_sprite(t_data *data);

// Door

int				doors_input(t_data *data);
uint32_t		get_col_px_colour_door(double calc_h, t_data *data, t_pfv pfv,
					mlx_texture_t *door_state);
void			open_door(t_data *data);
void			check_player_can_open_door(t_data *data,
					t_pfv pfv);
void			check_close_door(t_data *data);

// Exit

void			exit_game(t_data *data);

// Print

void			print_map(char **map);
uint32_t		get_col_px_colour(double calc_h, t_data *data, t_pfv pfv);
void			print_and_exit(char *message, int fd, int exit_code);

// Free

void			free_string_array(char **str_array);
int				free_string_array_and_return(char **str_array, int to_return);

// Utils

char			*ft_strjoin_free(char *s1, char *s2);
bool			can_move(char point);
bool			is_wall(t_map *map, t_data *data, double ray_angle);

// Map utils

int				check_first_line(char *line, char *scd_line);
int				check_last_line(char *line, char *last_line);
int				line_has_valid_char(t_data *data, char *line, int y);
int				valid_surrounded_wall(t_data *data, int i, int j);
int				get_max_column(t_data *data);
char			*line_filled_with_2(char *line, int max_column);
bool			invalid_char(char *map);

#endif
