/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:43:37 by mateferr          #+#    #+#             */
/*   Updated: 2025/05/28 18:30:24 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	chunk_calc(int lst_size)
{
	if (lst_size > 500)
		return (14 + (lst_size - 500) / 75);
	else if (lst_size >= 400 && lst_size <= 500)
		return (14);
	else if (lst_size >= 200 && lst_size < 400)
		return (10);
	else if (lst_size >= 60 && lst_size < 200)
		return (6);
	else if (lst_size >= 40 && lst_size < 60)
		return (5);
	else if (lst_size >= 30 && lst_size < 40)
		return (4);
	else if (lst_size >= 20 && lst_size < 30)
		return (3);
	else if (lst_size >= 10 && lst_size < 20)
		return (2);
	return (1);
}

static void	move_count(t_list *stack_a, int chunks, int list_size)
{
	int		moves;
	char	*move;
	int		fd;

	fd = open("ps_result.txt", O_RDWR);
	moves = 0;
	move = get_next_line(fd);
	while (move)
	{
		moves++;
		move = get_next_line(fd);
	}
	close(fd);
	if (stack_a && is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_printf("size - %i, chunks - %i, elem - %i, moves - %i\n", list_size,
		chunks, list_size / chunks, moves);
}

int	count_bits(int nbr)
{
	int	count;

	count = 0;
	while (nbr > 0)
	{
		nbr = nbr / 2;
		count++;
	}
	return (count);
}






