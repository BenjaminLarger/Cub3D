/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:04:14 by demre             #+#    #+#             */
/*   Updated: 2023/12/02 22:01:10 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(const char *set, char c)
{
	while (*set != '\0')
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	int		i;
	int		start;
	int		end;

	start = 0;
	while (s1[start] && is_set(set, s1[start]) != 0)
		start++;
	end = ft_strlen(s1);
	while (end > start && is_set(set, s1[end - 1]) != 0)
		end--;
	trimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trimmed)
	{
		free(trimmed);
		return (NULL);
	}
	i = 0;
	while (i + start < end)
	{
		trimmed[i] = s1[start + i];
		i++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}

/*
#include <stdio.h>
int main(void)
{
	char	*string = "  4 h ello4 444 4 4 444 4";
	char	*set = " 4";
	char	*trimmed;

	printf("trim  : '%s'\n", set);
	printf("from  : '%s'\n", string);
	trimmed = ft_strtrim(string, set);
	printf("output: '%s'\n", trimmed);
	free(trimmed);
	
	char	*string2 = "  4 h ello4 444 4 4 444 4";
	char	*set2 = "";
	char	*trimmed2;

	printf("trim  : '%s'\n", set2);
	printf("from  : '%s'\n", string2);
	trimmed2 = ft_strtrim(string2, set2);
	printf("output: '%s'\n", trimmed2);
	free(trimmed2);

	char	*string3 = "";
	char	*set3 = " 4";
	char	*trimmed3;

	printf("trim  : '%s'\n", set3);
	printf("from  : '%s'\n", string3);
	trimmed3 = ft_strtrim(string3, set3);
	printf("output: '%s'\n", trimmed3);
	free(trimmed3);

	char	*string4 = " fff  f";
	char	*set4 = " f";
	char	*trimmed4;

	printf("trim  : '%s'\n", set4);
	printf("from  : '%s'\n", string4);
	trimmed4 = ft_strtrim(string4, set4);
	printf("output: '%s'\n", trimmed4);
	free(trimmed4);

	char	*string5 = "";
	char	*set5 = "";
	char	*trimmed5;

	printf("trim  : '%s'\n", set5);
	printf("from  : '%s'\n", string5);
	trimmed5 = ft_strtrim(string5, set5);
	printf("output: '%s'\n", trimmed5);
	free(trimmed5);

	return 0;
}
*/