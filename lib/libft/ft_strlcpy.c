/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:05:30 by demre             #+#    #+#             */
/*   Updated: 2024/03/13 12:25:27 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	char dest1[20] = "hello ";
	char dest2[20] = "hello ";
	char dest3[20] = "hello ";
	char dest4[20] = "hello ";
	char dest5[20] = "hello ";
	char dest6[20] = "hello ";
	printf("strlcpy   : %zu, %s\n", strlcpy(dest1, "crazy world", 5), dest1);
	printf("ft_strlcpy: %zu, %s\n", ft_strlcpy(dest2, "crazy world", 5), dest2);
	printf("strlcpy   : %zu, %s\n", strlcpy(dest3, "crazy world", 0), dest3);
	printf("ft_strlcpy: %zu, %s\n", ft_strlcpy(dest4, "crazy world", 0), dest4);
	printf("strlcpy   : %zu, %s\n", strlcpy(dest5, "crazy world", 20), dest5);
	printf("ft_strlcpy: %zu, %s\n", ft_strlcpy(dest6, "crazy world", 20), dest6);
	return 0;
}
*/