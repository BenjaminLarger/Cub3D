/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 13:05:35 by demre             #+#    #+#             */
/*   Updated: 2024/03/19 15:11:33 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate first occurence of character in string
 * @return A pointer to the first occurrence of character in str. If the 
 * character is not found, the function returns a null pointer.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && (unsigned char)*s != (unsigned char)c)
		s++;
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main()
{
	printf("%s\n", strchr("aa4cc4dd", '4'));
	printf("%s\n", ft_strchr("aa4cc4dd", '4'));
	printf("%s\n", strchr("aa4cc4dd", '4' + 256));
	printf("%s\n", ft_strchr("aa4cc4dd", '4' + 256));
	return 0;
}
*/