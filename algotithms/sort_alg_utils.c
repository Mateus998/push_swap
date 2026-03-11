/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:43:37 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 12:29:21 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	normalize_data(t_list *stack_a)
{
	int		ncount;
	t_list	*node1;
	t_list	*node2;
	int		size;
	int		size2;

	size = lstsize(stack_a);
	node1 = stack_a;
	while (size--)
	{
		node2 = stack_a;
		size2 = lstsize(stack_a);
		ncount = 1;
		while (size2--)
		{
			if (node2->data < node1->data)
				ncount++;
			node2 = node2->next;
		}
		node1->norm = ncount;
		node1 = node1->next;
	}
}

void	two_size_sort(t_list **stack_a)
{
	int	top;
	int	bot;

	if (!*stack_a || (*stack_a)->next == *stack_a)
		return ;
	top = (*stack_a)->data;
	bot = (*stack_a)->next->data;
	if (top > bot)
		write_op(sa(stack_a));
	return ;
}

void	three_size_sort(t_list **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	if (!*stack_a || (*stack_a)->next == *stack_a)
		return ;
	top = (*stack_a)->data;
	mid = (*stack_a)->next->data;
	bot = (*stack_a)->next->next->data;
	if (top > mid && top > bot)
	{
		write_op(ra(stack_a));
		if (mid > bot)
			write_op(sa(stack_a));
	}
	else if (top < mid && mid > bot && top < bot)
	{
		write_op(rra(stack_a));
		write_op(sa(stack_a));
	}
	else if (top > mid && top < bot)
		write_op(sa(stack_a));
	else if (top < mid && top > bot)
		write_op(rra(stack_a));
}

void	final_rotation(t_list **stack_a)
{
	t_list	*head;
	int		size;

	size = lstsize(*stack_a);
	head = find_bigger_smaller(*stack_a, 0);
	if (head->index <= size / 2)
		while (*stack_a != head)
			write_op(ra(stack_a));
	else if (head->index > size / 2)
		while (*stack_a != head)
			write_op(rra(stack_a));
}

int	is_sorted(t_list *a, t_list *b)
{
	int		size;
	t_list	*lst2;
	t_list	*node;

	size = lstsize(a);
	node = a;
	if (b != NULL)
	{
		return (0);
	}
	if (size == 1)
		return (1);
	while (size--)
	{
		lst2 = a;
		while (lst2 != node)
		{
			if (lst2->data > node->data)
				return (0);
			lst2 = lst2->next;
		}
		node = node->next;
	}
	return (1);
}
