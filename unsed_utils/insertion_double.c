/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:23:11 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/28 12:53:46 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_small_num(t_list **stack_a, int lstsize)
{
	t_list	*node;
	t_list	*small;

	node = *stack_a;
	small = node;
	while (node)
	{
		if (small->data > node->data)
			small = node;
		node = node->next;
	}
	if (small->index == 0)
		return (0);
	if (small->index <= lstsize / 2)
		return (3);
	else if (small->index > lstsize / 2)
		return (5);
	return (1);
}

static int	find_big_num(t_list **stack_b, int lstsize)
{
	t_list	*node;
	t_list	*big;

	node = *stack_b;
	big = node;
	while (node)
	{
		if (big->data < node->data)
			big = node;
		node = node->next;
	}
	if (big->index == 0)
		return (0);
	if (big->index <= lstsize / 2)
		return (3);
	else if (big->index > lstsize / 2)
		return (5);
	return (1);
}

static int move_control(t_list **stack_a, t_list **stack_b, int fd)
{
	int move_a;
	int move_b;

	move_a = find_small_num(stack_a, lstsize(*stack_a));
	move_b = find_big_num(stack_b, lstsize(*stack_b));
	if (move_a == 0 && move_b == 0)
		return (0);
	if (move_a == 3 && move_b == 3)
		op_write(fd, rr(stack_a, stack_b));
	else if (move_a == 5 && move_b == 5)
		op_write(fd, rrr(stack_a, stack_b));
	else
	{
		if (move_a == 3)
			op_write(fd, ra(stack_a));
		else if (move_a == 5)
			op_write(fd, rra(stack_a));
		if (move_b == 3)
			op_write(fd, rb(stack_b));
		else if (move_b == 5)
			op_write(fd, rrb(stack_b));
	}
	return (1);
}

void	double_insertion_sort(t_list **stack_a, t_list **stack_b, int fd)
{
	int size;
	int i;
	int move;

	size = lstsize(*stack_a);
	i = size / 2;
	while (i--)
		op_write(fd, pb(stack_a, stack_b));
	print_list(*stack_b);
	while (size--)
	{
		move = 1;
		while (move)
			move = move_control(stack_a, stack_b, fd);
		op_write(fd, pb(stack_a, stack_b));
		op_write(fd, sb(stack_b));
		op_write(fd, pa(stack_a, stack_b));
	}
	// while (*stack_b)
	// 	op_write(fd, pa(stack_a, stack_b));
}
