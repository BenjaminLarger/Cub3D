/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:39:34 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 16:52:55 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d\n", ft_memcmp("abcdef", "abcdef", 5));
	printf("%d\n", ft_memcmp("aaa", "aab", 5));
	printf("%d\n", memcmp("test\200", "test\0", 6));
	printf("%d\n", ft_memcmp("test\200", "test\0", 6));
	printf("%d\n", memcmp("test", "test", 6));
	printf("%d\n", ft_memcmp("test", "test", 6));
	printf("%d\n", memcmp("", "", 6));
	printf("%d\n", ft_memcmp("", "", 6));
	printf("%d\n", memcmp("abcdef", "abc\375xx", 5));
	printf("%d\n", ft_memcmp("abcdef", "abc\375xx", 5));
	
	return 0;
}
*/