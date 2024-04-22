/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:05:30 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 14:19:55 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	dst_len = 0;
	while (dst[dst_len])
		dst_len++;
	src_len = 0;
	while (src[src_len])
		src_len++;
	i = 0;
	if (dstsize == 0)
		return (dstsize + src_len);
	while (src[i] != '\0' && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dst_len < dstsize)
		return (dst_len + src_len);
	else
		return (dstsize + src_len);
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
	printf("strlcat   : %zu, %s\n", strlcat(dest1, "crazy world", 5), dest1);
	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dest2, "crazy world", 5), dest2);
	printf("strlcat   : %zu, %s\n", strlcat(dest3, "crazy world", 0), dest3);
	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dest4, "crazy world", 0), dest4);
	printf("strlcat   : %zu, %s\n", strlcat(dest5, "crazy world", 20), dest5);
	printf("ft_strlcat: %zu, %s\n", ft_strlcat(dest6, "crazy world", 20), dest6);
	return 0;
}
*/