/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:48:54 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 11:48:57 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	annotate_moves(t_list *b, t_list *a)
{
	t_list	*tmp;
	int		size_a;
	int		size;

	tmp = b;
	size_a = lstsize(a);
	size = lstsize(b);
	while (size--)
	{
		tmp->target = target_node_ba(tmp, a, size_a);
		tmp->moves = move_ctrl(tmp, tmp->target);
		tmp = tmp->next;
	}
}

t_list	*find_cheapest_node(t_list *b)
{
	t_list	*cheapest;
	t_list	*tmp;
	int		size;

	cheapest = b;
	tmp = b;
	size = lstsize(b);
	while (size--)
	{
		if (tmp->moves < cheapest->moves)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	single_moves(t_list **a, t_list **b, t_list *target_a, t_list *target_b)
{
	int	a_move;
	int	b_move;

	a_move = move_type(target_a);
	b_move = move_type(target_b);
	if (*a != target_a)
	{
		if (a_move == 1)
			write_op(ra(a));
		else
			write_op(rra(a));
	}
	if (*b != target_b)
	{
		if (b_move == 1)
			write_op(rb(b));
		else
			write_op(rrb(b));
	}
}

void	align_stacks(t_list **a, t_list **b, t_list *target_a, t_list *target_b)
{
	int	a_move;
	int	b_move;

	while (*a != target_a || *b != target_b)
	{
		a_move = move_type(target_a);
		b_move = move_type(target_b);
		if (*a != target_a && *b != target_b && a_move == b_move)
		{
			if (a_move == 1)
				write_op(rr(a, b));
			else
				write_op(rrr(a, b));
		}
		else
		{
			single_moves(a, b, target_a, target_b);
		}
	}
}

void	move_cheapest_from_b_to_a(t_list **a, t_list **b)
{
	t_list	*cheapest;
	t_list	*target_a;
	t_list	*target_b;

	if (!*b)
		return ;
	annotate_moves(*b, *a);
	cheapest = find_cheapest_node(*b);
	target_a = cheapest->target;
	target_b = cheapest;
	align_stacks(a, b, target_a, target_b);
	write_op(pa(a, b));
}
