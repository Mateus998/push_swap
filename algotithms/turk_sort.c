/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:53:04 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 11:15:58 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	turk_sort(t_list **a, t_list **b, int size)
{
	if (!a || !*a)
		return ;
	while (size-- > 3)
	{
		write_op(pb(a, b));
	}
	three_size_sort(a);
	while (*b)
	{
		move_cheapest_from_b_to_a(a, b);
	}
	final_rotation(a);
}
