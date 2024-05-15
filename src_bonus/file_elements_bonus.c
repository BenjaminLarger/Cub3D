/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_elements_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:20:02 by demre             #+#    #+#             */
/*   Updated: 2024/05/15 20:33:48 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_identifier_flags(t_id_flags *flag)
{
	flag->id_no = FALSE;
	flag->id_so = FALSE;
	flag->id_we = FALSE;
	flag->id_ea = FALSE;
	flag->id_f = FALSE;
	flag->id_c = FALSE;
}

static void	get_element(char **name, char **split_line, int *flag,
	int *n_elements)
{
	int	len;

	len = ft_strlen(split_line[1]);
	if (split_line[1][len - 1] != '\n')
		len++;
	*name = (char *)malloc((len) * sizeof(char));
	if (!(*name))
	{
		free_string_array(split_line);
		print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
	}
	ft_strlcpy(*name, split_line[1], len);
	*flag = TRUE;
	*n_elements += 1;
	free_string_array(split_line);
}

static void	get_colour(unsigned int *name, char **split_line, int *flag,
	int *n_elements)
{
	int		len;
	char	*temp;

	len = ft_strlen(split_line[1]);
	temp = (char *)malloc(len * sizeof(char));
	if (!temp)
	{
		free_string_array(split_line);
		print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
	}
	ft_strlcpy(temp, split_line[1], len);
	free_string_array(split_line);
	*name = rgb_to_hex(temp);
	free(temp);
	*flag = TRUE;
	*n_elements += 1;
}

static void	assign_elements(t_data *data, char **split_line,
	t_id_flags *flag, int *n_elements)
{
	if (!split_line || split_line[1] == NULL
		|| (split_line[2] != NULL
			&& (ft_strcmp(split_line[2], "\n") == 0 && split_line[3] != NULL)))
		print_and_exit("Wrong information on file line", 2, EXIT_FAILURE);
	if (ft_strcmp(split_line[0], "NO") == 0 && flag->id_no == FALSE)
		get_element(&data->north_path, split_line, &flag->id_no, n_elements);
	else if (ft_strcmp(split_line[0], "SO") == 0 && flag->id_so == FALSE)
		get_element(&data->south_path, split_line, &flag->id_so, n_elements);
	else if (ft_strcmp(split_line[0], "WE") == 0 && flag->id_we == FALSE)
		get_element(&data->west_path, split_line, &flag->id_we, n_elements);
	else if (ft_strcmp(split_line[0], "EA") == 0 && flag->id_ea == FALSE)
		get_element(&data->east_path, split_line, &flag->id_ea, n_elements);
	else if (ft_strcmp(split_line[0], "F") == 0 && flag->id_f == FALSE)
		get_colour(&data->floor_color, split_line, &flag->id_f, n_elements);
	else if (ft_strcmp(split_line[0], "C") == 0 && flag->id_c == FALSE)
		get_colour(&data->sky_color, split_line, &flag->id_c, n_elements);
	else
		print_and_exit("Wrong or duplicate identifier", 2, EXIT_FAILURE);
}

void	load_elements(int *n_elements, t_data *data, int fd)
{
	char		*line;
	char		**split_line;
	t_id_flags	flag;

	init_identifier_flags(&flag);
	while (*n_elements < 6)
	{
		line = ft_get_next_line(fd);
		if (!line)
			print_and_exit("Wrong data in file", 2, EXIT_FAILURE);
		split_line = ft_split(line, ' ');
		free(line);
		if (!split_line)
			print_and_exit(MALLOC_FAIL, 2, EXIT_FAILURE);
		if (ft_strcmp(split_line[0], "\n") == 0)
		{
			free_string_array(split_line);
			continue ;
		}
		assign_elements(data, split_line, &flag, n_elements);
	}
}
