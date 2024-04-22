/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:45:11 by demre             #+#    #+#             */
/*   Updated: 2024/02/03 14:11:13 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# define BUFFER_SIZE 1024
# include <stdlib.h>
# include <unistd.h>

char	*ft_get_next_line(int file_descriptor);
char	*read_buffer(int fd, char *remainder);
char	*get_line_with_nl(char **remainder);
char	*gnl_free_and_null(char **pointer);
char	*gnl_free_double(char **pointer1, char **pointer2);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_substr(char const *s, unsigned int start, size_t len);
char	*gnl_strjoin(char const *s1, char const *s2);
void	*gnl_calloc(size_t count, size_t size);

#endif