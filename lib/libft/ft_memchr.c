/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:08:48 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 16:11:01 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	unsigned char	first;
	size_t			i;

	string = (unsigned char *)s;
	first = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*string == first)
			return ((char *)string);
		i++;
		string++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *str = "aa4\133cc4dd";
	int n = 6;
	
	printf("string: %s\n", str);
	printf("memchr    '4' in first %d: %s\n", n, memchr(str, '4', n));
	printf("ft_memchr '4' in first %d: %s\n", n, ft_memchr(str, '4', n));
	printf("memchr    '4' in first %d: %s\n", n, memchr(str, '4' + 256, n));
	printf("ft_memchr '4' in first %d: %s\n", n, ft_memchr(str, '4' + 256, n));
	printf("memchr    'd' in first %d: %s\n", n, memchr(str, 'd', n));
	printf("ft_memchr 'd' in first %d: %s\n", n, ft_memchr(str, 'd', n));
	printf("memchr    '\133' in first %d: %s\n", n, memchr(str, '\133', n));
	printf("ft_memchr '\133' in first %d: %s\n", n, ft_memchr(str, '\133', n));
	return 0;
}
*/