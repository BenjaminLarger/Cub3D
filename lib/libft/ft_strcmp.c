/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blarger <blarger@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 18:08:15 by demre             #+#    #+#             */
/*   Updated: 2024/03/11 12:13:51 by blarger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Compares two strings.
 * @param s1 Pointer to the first null-terminated byte string to compare.
 * @param s2 Pointer to the second null-terminated byte string to compare.
 * @return An integer less than, equal to, or greater than zero if @p s1 is
 * found, respectively, to be less than, to match, or be greater than @p s2.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
