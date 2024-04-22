/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:20:43 by demre             #+#    #+#             */
/*   Updated: 2023/12/03 18:40:24 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;
	size_t	alloc_size;

	s_len = ft_strlen(s);
	if (start >= s_len || len == 0)
		alloc_size = 1;
	else if (s_len - start < len)
		alloc_size = s_len - start + 1;
	else
		alloc_size = len + 1;
	substr = (char *)malloc(alloc_size * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && start + i < s_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*
#include <stdio.h>
int main()
{
	char const *string = "       split       this for   me  !       ";

	char *substr1 = ft_substr(string, 7, 5);
	printf("substr: '%s'\n", substr1);

//	char *substr2 = ft_substr(string, 45, 14);
//	printf("substr: '%s'\n", substr2);

//	char *substr3 = ft_substr(string, 55, 14);
//	printf("substr: '%s'\n", substr3);

	free(substr1);
//	free(substr2);
//	free(substr3);
	return 0;
}
*/