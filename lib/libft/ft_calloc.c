/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:35:41 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 21:00:17 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
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

/*
#include <stdio.h>
int main(void)
{
	char *z1 = (char *)calloc(10, sizeof(char));
	char *z2 = (char *)ft_calloc(10, sizeof(char));
	printf("calloc   : '%d %d %d %d %d'\n", z1[0], z1[1], z1[2], z1[3], z1[4]);
	printf("ft_calloc: '%d %d %d %d %d'\n", z2[0], z2[1], z2[2], z2[3], z2[4]);
	free(z1);
	free(z2);
}
*/