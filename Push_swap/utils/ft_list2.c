/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:36:58 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 11:39:29 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*lastnode(t_list *lst)
{
	t_list	*head;

	head = lst;
	if (!lst)
		return (NULL);
	while (lst->next != head)
		lst = lst->next;
	return (lst);
}

void	print_list(t_list *lst)
{
	int	size;
	int	chunk;

	if (!lst)
		return ;
	size = lstsize(lst);
	chunk = 0;
	while (size--)
	{
		chunk++;
		ft_printf("%i\n", lst->data);
		if (chunk == 10)
		{
			ft_printf("\n");
			chunk = 0;
		}
		lst = lst->next;
	}
	ft_printf("\n---------------------------------------\n\n");
}

void	remove_node(t_list **lst, t_list *node)
{
	t_list	*list;

	if (!lst || !*lst || !node)
		return ;
	if (node == node->next)
	{
		*lst = NULL;
		node->next = NULL;
		node->prev = NULL;
		return ;
	}
	list = node->next;
	while (list != *lst)
	{
		list->index -= 1;
		list = list->next;
	}
	if (node == *lst)
		*lst = node->next;
	node->prev->next = node->next;
	node->next->prev = node->prev;
	node->next = NULL;
	node->prev = NULL;
}
