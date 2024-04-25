/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:24 by demre             #+#    #+#             */
/*   Updated: 2024/04/25 13:09:13 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
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
# include "errors.h"
# include "structures.h"

// Boolean

# define FALSE 0
# define TRUE 1
# define FAILURE 1
# define SUCCESS 0

// Map input

# define OUT ' '
# define WEST 'W'
# define WALL '1'
# define NORTH 'N'
# define SOUTH 'S'
# define EST 'E'
# define EMPTY '0'

# define WIDTH 1920
# define HEIGHT 1280
# define PLAYER_FOV 60
# define NUM_OF_RAYS 200
# define SENSIBILITY 0.01

// Initialisation

void			initialise(char *filename, t_data *data);
int				get_data_from_file(char *filename, t_data *data);
void			load_elements(int *n_elements, t_data *data, int fd);
unsigned int	rgb_to_hex(char *rgb_str);
int				load_map(t_data *data, int fd);

// Minimap

void			paint_minimap(t_data *data);

// User input

void			player_input(mlx_key_data_t keydata, void *param);

// Exit

void			exit_game(t_data *data);

// Print

void			print_map(char **map);
void			print_and_exit(char *message, int fd, int exit_code);

// Free

void			free_string_array(char **str_array);
void			free_n_string_array(char **str_array, int n);
int				free_string_array_and_return(char **str_array, int to_return);
int				free_n_string_array_and_return(char **str_array, int n,
					int to_return);

// Utils

char			*ft_strjoin_free(char *s1, char *s2);
bool			access_denied(char point);


// Map utils

int				check_horizontal_wall(char *line);
int				line_has_valid_char(t_data *data, char *line, int y);
int				valid_surrounded_wall(t_data *data, int i, int j);

// Dev utils

void			print_array(char **array, char *message);

#endif
