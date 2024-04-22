/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 18:41:21 by demre             #+#    #+#             */
/*   Updated: 2023/11/30 19:03:24 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	size_t	start;

	needle_len = 0;
	while (needle[needle_len])
		needle_len++;
	if (!needle_len)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		j = 0;
		start = i;
		while (haystack[i] == needle[j] && haystack[i] != '\0' && i < len)
		{
			i++;
			j++;
		}
		if (j == needle_len)
			return ((char *)&haystack[start]);
		i = start + 1;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char *haystack = "aa1 ee2 aa3 aa4 ee5 aa6";
	char *needle = "ee";
	printf("%s\n", strnstr(haystack, needle, 6));
	printf("%s\n", ft_strnstr(haystack, needle, 6));
	return 0;
}
*/