/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 11:38:13 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/04 10:49:42 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../get_next_line/get_next_line.h"
# include "../push_swap.h"

// bonus
int		read_instructions(t_list **a, t_list **b);
int		exe_instruc(char *line, t_list **a, t_list **b, int i);
int		exe_instruc2(char *line, t_list **a, t_list **b);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	free_get_next_line(int fd);

#endif