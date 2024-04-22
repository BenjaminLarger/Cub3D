/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:10:24 by demre             #+#    #+#             */
/*   Updated: 2023/12/04 09:23:13 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 1;
	if (!s || s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		else if (s[i] == c)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	**ft_clear(char **split, unsigned int j)
{
	while (j > 0)
	{
		free(split[j - 1]);
		split[j - 1] = NULL;
		j--;
	}
	free(split);
	return (NULL);
}

static char	**assign_words(char **split, const char *str, char c, int i)
{
	int	j;
	int	start;

	j = 0;
	start = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		start = i;
		while (str[i] != c && str[i])
			i++;
		if (start < i)
		{
			split[j] = ft_substr(str, start, (i - start));
			if (!split[j])
			{
				split = ft_clear(split, j);
				return (split);
			}
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;

	words = count_words(s, c);
	split = (char **)malloc((words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = assign_words(split, s, c, 0);
	return (split);
}

/*
#include <stdio.h>
int main(void)
{
	char	*s = "       split       this for   me  !       ";
	char	**split;

	printf("'%s'\n", s);
	split = ft_split(s, ' ');
	int i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
}
*/