/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:32:53 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 15:17:36 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	vchr(int c)
{
	if (c == '-')
		return (1);
	if (c == '+')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	if (c == ' ')
		return (3);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	return (rra(stack_a) + rrb(stack_b));
}

long	ft_atol(const char *str)
{
	int		s;
	long	num;

	s = 1;
	num = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == ' '))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str && vchr(*str) == 2)
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * s);
}
