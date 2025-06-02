/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_val_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:41:45 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 15:18:25 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	atol_arg(t_list **lst, char *arg)
{
	long	nbr;

	nbr = ft_atol(arg);
	if (nbr > MAX_INT || nbr < MIN_INT)
		return (0);
	if (!list_new(lst, nbr))
		return (0);
	return (1);
}

int	split_arg(t_list **lst, char *arg)
{
	char	**split;
	int		idx;
	int		result;

	split = ft_split(arg, ' ');
	if (!split)
		return (0);
	idx = -1;
	result = 1;
	while (split[++idx])
	{
		if (!atol_arg(lst, split[idx]))
		{
			result = 0;
			break ;
		}
	}
	idx = -1;
	while (split[++idx])
		free(split[idx]);
	free(split);
	return (result);
}

int	check_chr(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!vchr(*str))
			return (0);
		if (vchr(*str) == 1 && *(str + 1) == '\0')
			return (0);
		if (vchr(*str) == 1 && vchr(*(str + 1)) != 2)
			return (0);
		if (vchr(*str) == 2)
		{
			while (*str && *str != ' ')
				if (vchr(*str++) != 2)
					return (0);
		}
		else
			str++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	a;
	int	v;

	a = 1;
	while (ac > a)
	{
		if (!check_chr(av[a]))
			return (0);
		v = 0;
		if (vchr(av[a][v]) == 3)
		{
			while (av[a] && av[a][v] == ' ')
				v++;
			if (av[a][v] == '\0')
				return (0);
		}
		a++;
	}
	return (1);
}

int	check_duplicates(t_list **lst)
{
	t_list	*node;
	t_list	*cpy;
	int		size;

	node = *lst;
	size = lstsize(*lst);
	while (size--)
	{
		cpy = *lst;
		while (cpy != node)
		{
			if (cpy->data == node->data)
				return (0);
			cpy = cpy->next;
		}
		node = node->next;
	}
	normalize_data(*lst);
	return (1);
}
