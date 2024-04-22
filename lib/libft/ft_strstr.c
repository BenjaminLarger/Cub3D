/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:51:07 by blarger           #+#    #+#             */
/*   Updated: 2024/03/05 11:51:09 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp2(char *s1, char *s2, int i, int j)
{
	while (s2[j] != '\0')
	{
		if (s1[i] != s2[j])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[j]);
		}
		i++;
		j++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[j])
		{
			k = i;
			if (ft_strcmp2(&str[k], &to_find[j], 0, 0) == 0)
			{
				return (&str[i]);
			}
		}
		i++;
	}
	return (0);
}
