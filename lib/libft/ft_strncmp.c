/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:05:07 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 13:27:04 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%d\n", ft_strncmp("abcdef", "abcdef", 5));
	printf("%d\n", ft_strncmp("abcdef", "aabcdef", 5));
	printf("%s\n", "test\200");
	printf("%s\n", "test\0");
	printf("%d\n", strncmp("test\200", "test\0", 6));
	printf("%d\n", ft_strncmp("test\200", "test\0", 6));
	printf("%s\n", "abcdef");
	printf("%s\n", "abc\375xx");
	printf("%d\n", strncmp("abcdef", "abc\375xx", 5));
	printf("%d\n", ft_strncmp("abcdef", "abc\375xx", 5));
	
	return 0;
}
*/