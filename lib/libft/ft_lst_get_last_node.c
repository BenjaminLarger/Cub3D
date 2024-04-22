/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_last_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:34:55 by demre             #+#    #+#             */
/*   Updated: 2024/01/14 14:40:49 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_get_last_node(t_list *lst)
{
	int	length;
	int	i;

	length = ft_lst_get_size(lst);
	i = 1;
	while (i < length)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
