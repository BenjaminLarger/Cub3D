/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:31:57 by demre             #+#    #+#             */
/*   Updated: 2024/03/02 15:43:34 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if a character is a white-space character.
 *
 * This function checks whether the given character @p c is a white-space
 * character according to the ASCII standard. White-space characters include
 * space (' '), horizontal tab ('\t'), carriage return ('\r'), line feed ('\n'),
 * and vertical tab ('\v').
 *
 * @param c The character to be checked.
 * @return Returns 1 if the character is a white-space character, 0 otherwise.
 */
int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}
