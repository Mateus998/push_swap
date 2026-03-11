/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:49:31 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 11:49:33 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	move_type(t_list *node)
{
	int	size;

	size = lstsize(node);
	if (node->index == 0)
		return (0);
	else if (node->index <= size / 2)
		return (1);
	return (-1);
}

int	moves_count(t_list *node, int move)
{
	int	size;
	int	total;

	total = 0;
	size = lstsize(node);
	if (move == 1 || move == 0)
		total = node->index;
	else
		total = size - node->index;
	return (total);
}

int	move_ctrl(t_list *b, t_list *a)
{
	int	b_mv;
	int	a_mv;
	int	total;
	int	total_b;
	int	total_a;

	b_mv = move_type(b);
	a_mv = move_type(a);
	total_b = 0;
	total_a = 0;
	total = 0;
	if (b_mv != a_mv)
		total = moves_count(b, b_mv) + moves_count(a, a_mv);
	else if (b_mv == a_mv && b_mv != 0)
	{
		total_b = moves_count(b, b_mv);
		total_a = moves_count(a, a_mv);
		if (total_b > total_a)
			total = total_b;
		else
			total = total_a;
	}
	return (total);
}

t_list	*find_bigger_smaller(t_list *lst, int target)
{
	t_list	*node;
	int		size;

	node = lst;
	size = lstsize(lst);
	while (size--)
	{
		if (target)
		{
			if (node->norm < lst->norm)
				node = lst;
		}
		else
		{
			if (node->norm > lst->norm)
				node = lst;
		}
		lst = lst->next;
	}
	return (node);
}

t_list	*target_node_ba(t_list *b_nd, t_list *stk_a, int a_size)
{
	t_list	*target;
	t_list	*bigger;
	t_list	*smaller;

	bigger = find_bigger_smaller(stk_a, 1);
	smaller = find_bigger_smaller(stk_a, 0);
	if (b_nd->norm > bigger->norm)
		return (smaller);
	if (b_nd->norm < smaller->norm)
		return (smaller);
	target = bigger;
	while (a_size--)
	{
		if (b_nd->norm < stk_a->norm)
		{
			if (stk_a->norm - b_nd->norm < target->norm - b_nd->norm)
				target = stk_a;
		}
		stk_a = stk_a->next;
	}
	return (target);
}
