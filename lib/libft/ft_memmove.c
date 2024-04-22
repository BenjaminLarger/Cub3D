/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:21:53 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 19:34:42 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*input;
	char	*output;

	if (dst == NULL && src == NULL)
		return (NULL);
	input = (char *)src;
	output = (char *)dst;
	if (input < output)
	{
		while (len--)
			output[len] = input[len];
	}
	else
	{
		while (len--)
			*output++ = *input++;
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[30] = "hello world";
	char str2[20] = "hello world";
//	char str3[20] = "hello world";

	memmove(&str1[6], &str1[0], 4);
	ft_memmove(&str2[6], &str2[0], 4);

	printf("check %d\n", strcmp(str1, str2));
	printf("after memmove: '%s'\n", str1);
	printf("after ft_memmove: '%s'\n", str2);

	char *src1 = "test !\r\n";
	char dst1[0xF0];
	int size1 = strlen(src1);
	char *src2 = "test !\r\n";
	char dst2[0xF0];
	int size2 = strlen(src2);
	memmove(dst1, src1, size1);
	dst1[size1] = '\0'; 
	ft_memmove(dst2, src2, size2);
	dst2[size2] = '\0'; 
	printf("check %d\n", strcmp(dst1, dst2));
	printf("after memmove   : '%s'\n", dst1);
	printf("after ft_memmove: '%s'\n", dst2);

	printf("empty: '%s'\n", memmove("", "" - 1, 0));
	printf("empty: '%s'\n", ft_memmove("", "" - 1, 0));

}
*/