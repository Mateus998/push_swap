/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 12:09:32 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/04 15:58:09 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	if (c == 1)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	if (!input_validation(&stack_a, c, v))
		return (write(2, "Error\n", 6), 1);
	if (is_sorted(stack_a, stack_b))
		return (free_list(&stack_a), 0);
	size = lstsize(stack_a);
	if (size > 3)
		turk_sort(&stack_a, &stack_b, size);
	else if (size == 3)
		three_size_sort(&stack_a);
	else if (size == 2)
		two_size_sort(&stack_a);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
