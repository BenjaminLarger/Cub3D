/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: demre <demre@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:55:42 by demre             #+#    #+#             */
/*   Updated: 2024/01/14 18:07:37 by demre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Creates a new list by applying a function to the content of each 
 * node in an existing list.
 *
 * @param lst A pointer to a node in the input linked list.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a 
 * node if needed.
 * @return A pointer to the new list. Returns NULL if the allocation fails.
 */

t_list	*ft_lst_map(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*content;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		content = f(lst->content);
		new_node = ft_lst_new_node(content);
		if (!new_node)
		{
			del(content);
			ft_lst_delete_all(&new_lst, del);
			return (NULL);
		}
		ft_lst_add_back(&new_lst, new_node);
		lst = lst->next;
	}
	return (new_lst);
}
