/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wr_instructions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:42:16 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 11:42:19 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	r_instruction(int op)
{
	if (op == 6)
		write(1, "ra\n", 3);
	else if (op == 7)
		write(1, "rb\n", 3);
	else if (op == 13)
		write(1, "rr\n", 3);
	else if (op == 8)
		write(1, "rra\n", 4);
	else if (op == 9)
		write(1, "rrb\n", 4);
	else if (op == 17)
		write(1, "rrr\n", 4);
	else
		return (0);
	return (1);
}

int	write_op(int op)
{
	static int	moves;

	if (op == 1)
		write(1, "sa\n", 3);
	else if (op == 2)
		write(1, "sb\n", 3);
	else if (op == 3)
		write(1, "ss\n", 3);
	else if (op == 4)
		write(1, "pa\n", 3);
	else if (op == 5)
		write(1, "pb\n", 3);
	else
	{
		moves += r_instruction(op);
		return (moves);
	}
	moves++;
	return (moves);
}
