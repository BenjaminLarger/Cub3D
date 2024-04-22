/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:05:24 by demre             #+#    #+#             */
/*   Updated: 2024/04/22 14:59:41 by demre            ###   ########.fr       */
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

# define FALSE 0
# define TRUE 1
# define FAILURE 1
# define SUCCESS 0

// Exit

void	exit_game(t_data *data);

// Print

void	print_and_exit(char *message, int fd, int exit_code);

// Free

void	free_string_array(char **str_array);
void	free_n_string_array(char **str_array, int n);

#endif
