/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:22:52 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/28 15:16:43 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	check_bit(t_list **stack_a, t_list **stack_b, t_list **node,
		int bit_idx, int fd)
{
	int	node_bit;
	int	lsize;

	lsize = lstsize(*stack_a);
	node_bit = ((*node)->norm >> bit_idx) & 1;
	if (node_bit == 1)
		return ;
	if ((*node)->index <= lsize / 2)
	{
		while ((*node)->index != 0)
			op_write(fd, ra(stack_a));
	}
	else if ((*node)->index > lsize / 2)
	{
		while ((*node)->index != 0)
			op_write(fd, rra(stack_a));
	}
	op_write(fd, pb(stack_a, stack_b));
	*node = *stack_a;
}

static void	list_search(t_list **stack_a, t_list **stack_b, int bit_idx, int fd)
{
	t_list	*inode;
	t_list	*lnode;
	int		side;

	side = 1;
	inode = *stack_a;
	lnode = lastnode(*stack_a);
	while (inode->index < lnode->index)
	{
		if (side == 1)
		{
			check_bit(stack_a, stack_b, &inode, bit_idx, fd);
			inode = inode->next;
		}
		else
		{
			check_bit(stack_a, stack_b, &lnode, bit_idx, fd);
			if (!lnode->prev)
				lnode = lastnode(*stack_a);
			else
				lnode = lnode->prev;
		}
		side *= -1;
	}
}

void	radix_sort(t_list **stack_a, t_list **stack_b, int fd)
{
	int		bit_idx;
	int		bit_max;
	t_list	*node;
	
    normalize_data(*stack_a);
	bit_idx = 0;
	node = lastnode(*stack_a);
	bit_max = count_bits(node->index + 1);
	while (bit_idx < bit_max)
	{
		list_search(stack_a, stack_b, bit_idx, fd);
		while (*stack_b)
			op_write(fd, pa(stack_a, stack_b));
		bit_idx++;
	}
}
