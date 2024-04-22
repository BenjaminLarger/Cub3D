/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:43:33 by demre             #+#    #+#             */
/*   Updated: 2024/02/03 14:11:09 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

char	*gnl_free_and_null(char **pointer)
{
	free(*pointer);
	*pointer = NULL;
	return (NULL);
}

char	*gnl_free_double(char **pointer1, char **pointer2)
{
	free(*pointer1);
	*pointer1 = NULL;
	free(*pointer2);
	*pointer2 = NULL;
	return (NULL);
}

char	*read_buffer(int fd, char *remainder)
{
	char		*buffer;
	char		*temp;
	ssize_t		bytes_read;

	buffer = gnl_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (gnl_free_and_null(&remainder));
	bytes_read = 1;
	while (bytes_read > 0 && !gnl_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (gnl_free_double(&remainder, &buffer));
		buffer[bytes_read] = '\0';
		if (bytes_read > 0 && !remainder)
			remainder = gnl_substr(buffer, 0, gnl_strlen(buffer));
		else if (bytes_read > 0 && remainder)
		{
			temp = gnl_strjoin(remainder, buffer);
			free(remainder);
			remainder = temp;
		}
	}
	free(buffer);
	return (remainder);
}

char	*get_line_with_nl(char **remainder)
{
	char	*line;
	char	*str_from_the_nl;
	char	*temp;
	size_t	line_length;

	str_from_the_nl = gnl_strchr(*remainder, '\n');
	line_length = str_from_the_nl - *remainder + 1;
	line = gnl_substr(*remainder, 0, line_length);
	if (!line)
		return (gnl_free_and_null(remainder));
	if (gnl_strlen(str_from_the_nl) - 1 > 0)
	{
		temp = gnl_substr(str_from_the_nl + 1, 0,
				gnl_strlen(str_from_the_nl) + 1);
		free(*remainder);
		*remainder = temp;
	}
	else
		gnl_free_and_null(remainder);
	return (line);
}

char	*ft_get_next_line(int file_descriptor)
{
	static char	*remainder = NULL;
	char		*line;

	if (file_descriptor < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remainder = read_buffer(file_descriptor, remainder);
	if (remainder && gnl_strchr(remainder, '\n'))
		line = get_line_with_nl(&remainder);
	else if (remainder)
	{
		line = gnl_substr(remainder, 0, gnl_strlen(remainder));
		gnl_free_and_null(&remainder);
	}
	else
		line = NULL;
	return (line);
}

/*
#include <stdio.h>
#include <fcntl.h>
int main(int argc, char const *argv[])
{
	if (argc == 2)
	{
		int file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			printf("Error opening file\n");
			return (1);
		}
//		int i = 0;
		while (1)
		{
//			printf("\nGetting new line from main\n" NC);
			char *line = get_next_line(file_descriptor);
			if (!line)
			{
				printf("eof\n");
				close(file_descriptor);
				return (1);
			}
			printf("mainline: '%s'\n", line);
			free(line);
		}

		close(file_descriptor); 
	}
	else
		printf("incorrect parameter number\n");
	return (0);
}
*/