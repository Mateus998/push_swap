/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 12:23:23 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 11:27:55 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_validation(t_list **lst, int ac, char **av)
{
	int	a;
	int	v;

	a = 1;
	v = 0;
	if (!check_args(ac, av))
		return (0);
	while (ac > a)
	{
		v = 0;
		while (av[a][v] && av[a][v] != ' ')
			v++;
		if (av[a][v] == ' ')
		{
			if (!split_arg(lst, av[a]))
				return (free_list(lst), 0);
		}
		else if (!atol_arg(lst, av[a]))
			return (free_list(lst), 0);
		a++;
	}
	if (!check_duplicates(lst))
		return (free_list(lst), 0);
	return (1);
}
