/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:57:12 by demre             #+#    #+#             */
/*   Updated: 2023/11/30 20:55:35 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*c;

	i = 0;
	c = s;
	while (i < n)
	{
		c[i] = '\0';
		i++;
	}
}

/*
#include <stdio.h>
int main() {
    char buffer[10];

	printf("before: ");
	int i = 0;
    while (i < 10)
	{
        buffer[i] = i + 1;
		printf("%d ", buffer[i]);
		i++;
    }
	printf("\n");

    ft_bzero(buffer, 10);

	printf("after : ");
	i = 0;
    while (i < 10)
	{
        printf("%d ", buffer[i]);
		i++;
    }
	printf("\n");
    return 0;
}
*/