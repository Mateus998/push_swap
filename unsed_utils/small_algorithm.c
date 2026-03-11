/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 10:38:54 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/30 12:36:34 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	two_size_sort(t_list **stack_a, int fd)
{
	int	top;
	int	bot;

	if (!*stack_a || (*stack_a)->next == *stack_a)
		return ;
	top = (*stack_a)->data;
	bot = (*stack_a)->next->data;
	if (top > bot)
		op_write(fd, sa(stack_a));
	return ;
}

static void	three_size_sort(t_list **stack_a, int fd)
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
		op_write(fd, ra(stack_a));
		if (mid > bot)
			op_write(fd, sa(stack_a));
	}
	else if (top < mid && mid > bot && top < bot)
	{
		op_write(fd, rra(stack_a));
		op_write(fd, sa(stack_a));
	}
	else if (top > mid && top < bot)
		op_write(fd, sa(stack_a));
	else if (top < mid && top > bot)
		op_write(fd, rra(stack_a));
}

static void	find_small_num(t_list **stack_a, t_list **stack_b, int fd)
{
	int		size;
	int		idx;
	t_list	*small;

	small = *stack_a;
	size = lstsize(*stack_a);
	while (size--)
	{
		if (small->n_data > (*stack_a)->n_data)
			small = *stack_a;
		*stack_a = (*stack_a)->next;
	}
	size = lstsize(*stack_a);
	idx = small->index;
	if (idx <= size / 2)
		while (idx--)
			op_write(fd, ra(stack_a));
	else
		while (idx++ < size)
			op_write(fd, rra(stack_a));
	op_write(fd, pb(stack_a, stack_b));
}

void	small_size_sort(t_list **stack_a, t_list **stack_b, int fd)
{
	int	size;

	size = lstsize(*stack_a);
	if (size <= 2)
		return (two_size_sort(stack_a, fd));
	size -= 3;
	while (size--)
		find_small_num(stack_a, stack_b, fd);
	three_size_sort(stack_a, fd);
	while (*stack_b)
		op_write(fd, pa(stack_a, stack_b));
}
