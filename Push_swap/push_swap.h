/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:36:36 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/04 10:49:15 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_list
{
	int				data;
	int				index;
	int				norm;
	int				moves;
	struct s_list	*target;
	struct s_list	*prev;
	struct s_list	*next;
}					t_list;

// instructions
int					sa(t_list **stack_a);
int					sb(t_list **stack_b);
int					ss(t_list **stack_a, t_list **stack_b);
int					pa(t_list **stack_a, t_list **stack_b);
int					pb(t_list **stack_a, t_list **stack_b);
int					ra(t_list **stack_a);
int					rb(t_list **stack_b);
int					rr(t_list **stack_a, t_list **stack_b);
int					rra(t_list **stack_a);
int					rrb(t_list **stack_b);
int					rrr(t_list **stack_a, t_list **stack_b);

// utils
char				**ft_split(char const *s, char c);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *str);
long				ft_atol(const char *str);
int					vchr(int c);
int					write_op(int op);
int					is_sorted(t_list *a, t_list *b);

// list
int					list_new(t_list **lst, int value);
void				free_list(t_list **lst);
void				lstadd_front(t_list **lst, t_list *new);
void				lstadd_back(t_list **lst, t_list *new);
int					lstsize(t_list *lst);
void				print_list(t_list *lst);
t_list				*lastnode(t_list *lst);
void				remove_node(t_list **lst, t_list *node);

// algorithm
void				normalize_data(t_list *stack_a);
void				final_rotation(t_list **stack_a);
void				three_size_sort(t_list **stack_a);
void				two_size_sort(t_list **stack_a);

// turk_sort
void				turk_sort(t_list **a, t_list **b, int size);
t_list				*target_node_ba(t_list *b_nd, t_list *stk_a, int a_size);
t_list				*find_bigger_smaller(t_list *lst, int target);
int					move_ctrl(t_list *b, t_list *a);
int					moves_count(t_list *node, int move);
int					move_type(t_list *node);
void				move_cheapest_from_b_to_a(t_list **a, t_list **b);
void				align_stacks(t_list **a, t_list **b, t_list *target_a,
						t_list *target_b);
void				single_moves(t_list **a, t_list **b, t_list *target_a,
						t_list *target_b);
t_list				*find_cheapest_node(t_list *b);
void				annotate_moves(t_list *b, t_list *a);

// input validation
int					input_validation(t_list **lst, int ac, char **av);
int					check_duplicates(t_list **lst);
int					check_args(int ac, char **av);
int					check_chr(char *str);
int					split_arg(t_list **lst, char *arg);
int					atol_arg(t_list **lst, char *arg);

#endif