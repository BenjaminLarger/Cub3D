/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:05:35 by demre             #+#    #+#             */
/*   Updated: 2023/12/01 13:50:36 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	while (i >= 0)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s--;
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s\n", strrchr("aa4cc4dd", '4'));
	printf("%s\n", ft_strrchr("aa4cc4dd", '4'));
	printf("%s\n", strrchr("aa4cc4dd", '4' + 256));
	printf("%s\n", ft_strrchr("aa4cc4dd", '4' + 256));
	return 0;
}
*/