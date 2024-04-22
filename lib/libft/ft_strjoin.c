/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:36:04 by demre             #+#    #+#             */
/*   Updated: 2023/12/02 14:02:16 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	concat = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		concat[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		concat[s1_len + i] = s2[i];
		i++;
	}
	concat[s1_len + i] = '\0';
	return (concat);
}
