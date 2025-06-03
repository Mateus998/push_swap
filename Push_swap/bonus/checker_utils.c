/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:38:03 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/03 19:06:15 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2)
	{
		return (0);
	}
	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n)
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	exe_instruc2(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	exe_instruc(char *line, t_list **a, t_list **b, int i)
{
	static int	moves;

	if (i)
		return (moves);
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b);
	else
	{
		if (!exe_instruc2(line, a, b))
			return (0);
	}
	return (++moves);
}

int	read_instructions(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (!exe_instruc(line, a, b, 0))
		{
			free(line);
			free_get_next_line(STDIN_FILENO);
			return (0);
		}
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (1);
}

void free_get_next_line(int fd)
{
	char *line;
	
    line = get_next_line(fd);
    while (line)
    {
        free(line);
        line = get_next_line(fd);
    }
}
