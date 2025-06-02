/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:32:59 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/30 12:36:28 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_nbr(t_list *stack, int min_chunk, int max_chunk)
{
	int	size;

	if (!stack)
		return (-1);
	size = lstsize(stack);
	while (!(stack->n_data >= min_chunk && stack->n_data <= max_chunk)
		&& stack->index < size - 1)
		stack = stack->next;
	if (stack->n_data >= min_chunk && stack->n_data <= max_chunk)
	{
		return (stack->index);
	}
	return (-1);
}

static void	sort_move(t_list **stack_a, t_list **stack_b, int fd, int idx)
{
	int	size;

	size = lstsize(*stack_a);
	if (idx <= size / 2)
		while (idx--)
			op_write(fd, ra(stack_a));
	else
		while (idx++ < size)
			op_write(fd, rra(stack_a));
	op_write(fd, pb(stack_a, stack_b));
}

static void	final_sort(t_list **stack_a, t_list **stack_b, int fd)
{
	int		size;
	int		idx;
	t_list	*big;

	while (*stack_b)
	{
		big = *stack_b;
		size = lstsize(*stack_b);
		while (size--)
		{
			if (big->n_data < (*stack_b)->n_data)
				big = *stack_b;
			*stack_b = (*stack_b)->next;
		}
		size = lstsize(*stack_b);
		idx = big->index;
		if (idx <= size / 2)
			while (idx--)
				op_write(fd, rb(stack_b));
		else
			while (idx++ < size)
				op_write(fd, rrb(stack_b));
		op_write(fd, pa(stack_a, stack_b));
	}
}

static void	set_chunk_value(int *min, int *max, int size, int chunks, int i)
{
	int	rest;

	rest = size % chunks;
	if (rest && i <= rest)
	{
		*max = i * (size / chunks) + i;
		*min = *max - (size / chunks);
	}
	else if (rest && i > rest)
	{
		*max = *max + (size / chunks);
		*min = *max - (size / chunks) + 1;
	}
	else
	{
		*max = i * (size / chunks);
		*min = *max - (size / chunks) + 1;
	}
}

void	chunks_sort(t_list **stack_a, t_list **stack_b, int fd, int chunks)
{
	int	min_chunk;
	int	max_chunk;
	int	size;
	int	nbr_idx;
	int	i;

	size = lstsize(*stack_a);
	normalize_data(*stack_a);
	i = 1;
	while (i <= chunks)
	{
		set_chunk_value(&min_chunk, &max_chunk, size, chunks, i);
		nbr_idx = find_nbr(*stack_a, min_chunk, max_chunk);
		while (*stack_a && nbr_idx != -1)
		{
			sort_move(stack_a, stack_b, fd, nbr_idx);
			nbr_idx = find_nbr(*stack_a, min_chunk, max_chunk);
		}
		i++;
	}
	final_sort(stack_a, stack_b, fd);
}
