/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:17:22 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/30 12:36:51 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lstadd_front(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		lstadd_back(lst, new);
		return ;
	}
	new->next = *lst;
	new->index = 0;
	new->prev = lastnode(*lst);
	new->prev->next = new;
	(*lst)->prev = new;
	node = *lst;
	while (node != new)
	{
		node->index += 1;
		node = node->next;
	}
	*lst = new;
}

void	lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (!lst || !new)
		return ;
	node = *lst;
	if (node == NULL)
	{
		new->index = 0;
		new->next = new;
		new->prev = new;
		*lst = new;
	}
	else
	{
		node = lastnode(*lst);
		new->index = node->index + 1;
		node->next = new;
		new->prev = node;
		new->next = *lst;
		(*lst)->prev = new;
	}
}

int	list_new(t_list **lst, int value)
{
	t_list	*new;

	if (!lst)
		return (0);
	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->data = value;
	new->prev = NULL;
	new->next = NULL;
	new->target = NULL;
	new->index = 0;
	new->norm = 0;
	new->moves = 0;
	lstadd_back(lst, new);
	return (1);
}

void	free_list(t_list **lst)
{
	t_list	*next;
	int		size;

	if (!lst || !*lst)
		return ;
	size = lstsize(*lst);
	while (size--)
	{
		next = (*lst)->next;
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		free(*lst);
		*lst = next;
	}
	*lst = NULL;
}

int	lstsize(t_list *lst)
{
	int		size;
	t_list	*head;

	if (!lst)
		return (0);
	head = lst;
	size = 0;
	while (lst->next != head)
	{
		size++;
		lst = lst->next;
	}
	size++;
	return (size);
}
