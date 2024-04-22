/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:34:15 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 11:46:36 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char			*byte_string;
	unsigned char	byte_value;

	byte_string = b;
	byte_value = c;
	while (len > 0)
	{
		*byte_string = byte_value;
		byte_string++;
		len--;
	}
	return (b);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[10] = "abcdefghi";
	char str2[10] = "abcdefghi";

	memset(&str1[2], '0', 3);
	printf("after memset   : %s\n", str1);

	ft_memset(&str2[2], '0', 3);
	printf("after ft_memset: %s\n", str2);
}
*/