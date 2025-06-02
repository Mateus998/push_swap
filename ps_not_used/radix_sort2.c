/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:40:30 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/28 18:20:26 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_bit(t_list **stack_a, t_list **stack_b, t_list **node,
		int bit_idx, int fd)
{
	int	node_bit;

	node_bit = ((*node)->norm >> bit_idx) & 1;
	if (node_bit == 1)
		return (0);
	while ((*node)->index != 0)
		op_write(fd, ra(stack_a));
	op_write(fd, pb(stack_a, stack_b));
	*node = *stack_a;
	return (1);
}

static void	list_search(t_list **stack_a, t_list **stack_b, int bit_idx, int fd)
{
	t_list	*node;

	node = *stack_a;
	while (node)
	{
		if (!check_bit(stack_a, stack_b, &node, bit_idx, fd))
			node = node->next;
	}
}

void	radix_sort2(t_list **stack_a, t_list **stack_b, int fd)
{
	int		bit_max;
	int		bit_idx;
	t_list	*node;
	int		size;

	bit_idx = 0;
	normalize_data(*stack_a);
	node = lastnode(*stack_a);
	bit_max = count_bits(node->index + 1);
	while (bit_max > bit_idx)
	{
		list_search(stack_a, stack_b, bit_idx, fd);
		size = lstsize(*stack_b);
		while (size--)
			op_write(fd, pa(stack_a, stack_b));
		bit_idx++;
	}
}
