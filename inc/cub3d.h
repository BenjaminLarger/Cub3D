/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:24 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 16:31:31 by demre            ###   ########.fr       */
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
# define EMPTY ' '
# define WEST 'W'
# define WALL 1
# define NORTH 'N'
# define SOUTH 'S'
# define EST 'E'

// Initialisation

void	initialise(char *filename, t_data *data);
int		get_data_from_file(char *filename, t_data *data);

// User input

void	player_input(mlx_key_data_t keydata, void *param);

// Exit

void	exit_game(t_data *data);

// Print

void	print_and_exit(char *message, int fd, int exit_code);

// Free

void	free_string_array(char **str_array);
void	free_n_string_array(char **str_array, int n);
int		free_string_array_and_return(char **str_array, int to_return);
int		free_n_string_array_and_return(char **str_array, int n, int to_return);


// Dev utils


void	print_array(char **array, char *message);

#endif
