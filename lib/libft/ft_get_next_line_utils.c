/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:35:54 by demre             #+#    #+#             */
/*   Updated: 2024/02/03 14:09:00 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (len);
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	while (*s != '\0' && (unsigned char)*s != (unsigned char)c)
		s++;
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;
	size_t	alloc_size;

	s_len = gnl_strlen(s);
	if (start >= s_len || len == 0)
		alloc_size = 1;
	else if (s_len - start < len)
		alloc_size = s_len - start + 1;
	else
		alloc_size = len + 1;
	substr = (char *)malloc(alloc_size * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && start + i < s_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	i;
	size_t	s1_len;

	s1_len = gnl_strlen(s1);
	concat = (char *)malloc((s1_len + gnl_strlen(s2) + 1) * sizeof(char));
	if (!concat)
	{
		free((void *)s2);
		return (NULL);
	}
	i = -1;
	while (s1[++i])
		concat[i] = s1[i];
	i = -1;
	while (s2[++i])
		concat[s1_len + i] = s2[i];
	concat[s1_len + i] = '\0';
	return (concat);
}

void	*gnl_calloc(size_t count, size_t size)
{
	char	*byte_string;
	size_t	i;
	size_t	len;

	byte_string = (char *)malloc(count * size);
	if (!byte_string)
		return (NULL);
	i = 0;
	len = count * size;
	while (i < len)
	{
		byte_string[i] = 0;
		i++;
	}
	return (byte_string);
}
