
#include "../push_swap.h"

static t_list	*target_node_ab(t_list *b_nd, t_list *stk_a, int a_size)
{
	t_list	*target;
	t_list	*bigger;
	t_list	*smaller;

	bigger = find_bigger_smaller(stk_a, 1);
	smaller = find_bigger_smaller(stk_a, 0);
	if (b_nd->norm > bigger->norm)
		return (bigger);
	if (b_nd->norm < smaller->norm)
		return (bigger);
	target = smaller;
	while (a_size--)
	{
		if (b_nd->norm > stk_a->norm)
		{
			if (b_nd->norm - stk_a->norm < b_nd->norm - target->norm)
				target = stk_a;
		}
		stk_a = stk_a->next;
	}
	return (target);
}

static void annotate_moves2(t_list *b, t_list *a)
{
	t_list *tmp;
	int size_b;
	int size;

	tmp = a;
	size_b = lstsize(b);
	size = lstsize(a);
	while (size--)
	{
		tmp->target = target_node_ab(tmp, b, size_b);
		tmp->moves = move_ctrl(tmp, tmp->target);
		tmp = tmp->next;
	}
}

static void single_moves2(t_list **a, t_list **b, t_list *target_a, t_list *target_b)
{
	int a_move;
	int b_move;

	a_move = move_type(target_a);
	b_move = move_type(target_b);
	if (*a != target_a)
	{
		if (a_move == 1)
			ra(a);
		else
			rra(a);
	}
	if (*b != target_b)
	{
		if (b_move == 1)
			rb(b);
		else
			rrb(b);
	}
}

static void align_stacks2(t_list **a, t_list **b, t_list *target_a, t_list *target_b)
{
	int a_move;
	int b_move;

	while (*a != target_a || *b != target_b)
	{
		a_move = move_type(target_a);
		b_move = move_type(target_b);

		if (*a != target_a && *b != target_b && a_move == b_move)
		{
			if (a_move == 1)
				rr(a, b);
			else
				rrr(a, b);
		}
		else
		{
			single_moves2(a, b, target_a, target_b);
		}
	}
}

static void move_cheapest_from_a_to_b(t_list **a, t_list **b)
{
	t_list *cheapest;
	t_list *target_a;
	t_list *target_b;

	if (!*a)
		return;
	annotate_moves2(*b, *a);
	cheapest = find_cheapest_node(*a);
	target_b = cheapest->target;
	target_a = cheapest;
	align_stacks2(a, b, target_a, target_b);
	pb(a, b);
}

void	turk_double_calc(t_list **a, t_list **b, int size)
{
	if (!a || !*a)
		return ;
	if (size >= 5)
		pb(a, b);
	if (size >= 4)
		pb(a, b);
	size = lstsize(*a);
	while (size-- > 3)
	{
		move_cheapest_from_a_to_b(a, b);
	}
	three_size_sort(a);
	while (*b)
	{
		move_cheapest_from_b_to_a(a, b);
	}
	final_rotation(a);
}
