/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:38:30 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 11:11:29 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_list **stack_a)
{
	t_list	*rnode;

	if (!stack_a || (*stack_a)->next == *stack_a)
		return (0);
	rnode = *stack_a;
	remove_node(stack_a, rnode);
	lstadd_back(stack_a, rnode);
	return (6);
}

int	rb(t_list **stack_b)
{
	t_list	*rnode;

	if (!stack_b || (*stack_b)->next == *stack_b)
		return (0);
	rnode = *stack_b;
	remove_node(stack_b, rnode);
	lstadd_back(stack_b, rnode);
	return (7);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	return (ra(stack_a) + rb(stack_b));
}

int	rra(t_list **stack_a)
{
	t_list	*node;

	if (!stack_a || (*stack_a)->next == *stack_a)
		return (0);
	node = lastnode(*stack_a);
	remove_node(stack_a, node);
	lstadd_front(stack_a, node);
	return (8);
}

int	rrb(t_list **stack_b)
{
	t_list	*node;

	if (!stack_b || (*stack_b)->next == *stack_b)
		return (0);
	node = lastnode(*stack_b);
	remove_node(stack_b, node);
	lstadd_front(stack_b, node);
	return (9);
}
