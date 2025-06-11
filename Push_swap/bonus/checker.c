/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:37:52 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:34:44 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int c, char **v)
{
	t_list	*stk_a;
	t_list	*stk_b;

	if (c == 1)
		return (0);
	stk_a = NULL;
	stk_b = NULL;
	if (!input_validation(&stk_a, c, v))
		return (free_list(&stk_a), free_list(&stk_b), write(2, "Error\n", 6),
			1);
	if (!read_instructions(&stk_a, &stk_b))
		return (write(2, "Error\n", 6), 1);
	if (is_sorted(stk_a, stk_b))
		ft_printf("OK\nmoves- %i\n", exe_instruc(NULL, &stk_a, &stk_b, 1));
	else
		ft_printf("KO\n");
	free_list(&stk_a);
	free_list(&stk_b);
	return (0);
}
