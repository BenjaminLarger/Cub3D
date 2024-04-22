/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delete_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:33:13 by demre             #+#    #+#             */
/*   Updated: 2024/01/14 14:47:38 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * - Delete the content of a node using the function ’del’.
 * - Free the node.
 * - Repeat for successors in linked list.
 * - Set pointer to the list to NULL.
 *
 * @param lst A pointer to a pointer to the node to be deleted.
 * @param del The address of the function used to delete the content of a node.
 */

void	ft_lst_delete_all(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_node;

	while (*lst)
	{
		tmp_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp_node;
	}
	lst = NULL;
}
