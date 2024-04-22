/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 20:30:51 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 15:04:33 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char	*input;
	char	*output;

	if (dst == NULL && src == NULL)
		return (NULL);
	input = (char *)src;
	output = dst;
	while (len > 0)
	{
		*output = *input;
		output++;
		input++;
		len--;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[10] = "abcdefghi";
	char str2[10] = "abcdefghi";
//	char str3[10] = "abcdefghi";
//	char str4[10] = "abcdefghi";
	char str5[10] = "abcdefghi";
	char str6[10] = "abcdefghi";

	memcpy(&str1[3], &str1[0], 6);
	printf("after memcpy   : %s\n", str1);

	ft_memcpy(&str2[3], &str2[0], 6);
	printf("after ft_memcpy: %s\n", str2);

	printf("after memcpy: %s\n", memcpy(NULL, NULL, 3));
//	printf("after memcpy: %s\n", memcpy(&str3[3], NULL, 3));
//	printf("after memcpy: %s\n", memcpy(((void *)0), &str4[3], 3));
	printf("after ft_memcpy: %s\n", ft_memcpy(NULL, NULL, 3));
	printf("after ft_memcpy: %s\n", ft_memcpy(&str5[3], ((void *)0), 3));
	printf("after ft_memcpy: %s\n", ft_memcpy(((void *)0), &str6[3], 3));

//	int numbers[] = {1, 2, 3, 4};
//	int dst_n[4];
//	ft_memcpy(dst_n, numbers, 4 * sizeof(int));
//	printf("%d %d %d %d\n", dst_n[0], dst_n[1], dst_n[2], dst_n[3]);
}
*/