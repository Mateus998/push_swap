/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:50:56 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 17:46:58 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_list **stack_a)
{
	t_list	*node;

	if (!stack_a || !*stack_a || (*stack_a)->next == *stack_a)
		return (0);
	node = (*stack_a)->next;
	remove_node(stack_a, node);
	lstadd_front(stack_a, node);
	return (1);
}

int	sb(t_list **stack_b)
{
	t_list	*node;

	if (!stack_b || !*stack_b || (*stack_b)->next == *stack_b)
		return (0);
	node = (*stack_b)->next;
	remove_node(stack_b, node);
	lstadd_front(stack_b, node);
	return (2);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	return (sa(stack_a) + sb(stack_b));
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*b_node;

	if (!stack_a || !stack_b)
		return (0);
	b_node = *stack_b;
	if (!b_node)
		return (0);
	remove_node(stack_b, b_node);
	lstadd_front(stack_a, b_node);
	return (4);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*a_node;

	if (!stack_a || !stack_b)
		return (0);
	a_node = *stack_a;
	if (!a_node)
		return (0);
	remove_node(stack_a, a_node);
	lstadd_front(stack_b, a_node);
	return (5);
}
