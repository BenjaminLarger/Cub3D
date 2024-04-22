/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_add_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:46:55 by demre             #+#    #+#             */
/*   Updated: 2024/01/14 14:40:45 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_add_back(t_list **lst, t_list *new_node)
{
	t_list	*last_node;

	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last_node = ft_lst_get_last_node(*lst);
		last_node->next = new_node;
	}
}
