/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 11:55:19 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_finish(t_stack *stk)
{
	int		max_a;
	int		min_a;
	int		size;
	int		*t;
	t_list	*aux;

	aux = stk->stack_a;
	t = aux->content;
	max_a = *t;
	min_a = *t;
	stk_limits(aux, &max_a, &min_a);
	size = ft_lstsize(stk->stack_a) / 2;
	while (finish_check(stk) < 1)
	{
		if (ft_lstpos(stk->stack_a, &min_a) < size)
			rotate_a(stk, 0);
		else if (ft_lstpos(stk->stack_a, &min_a) >= size)
			reverse_rotate_a(stk, 0);
		t = stk->stack_a->content;
	}
}

static void	push_back(t_stack *stk)
{
	int		max_a;
	int		min_a;
	int		*t;
	t_list	*actions;

	t = stk->stack_a->content;
	max_a = *t;
	min_a = *t;
	stk_limits(stk->stack_a, &max_a, &min_a);
	actions = calculate_push_back(stk, &max_a, &min_a);
	parse_move(stk, actions);
	ft_lstclear(&actions, (void *) ft_delete);
}

static void	start_move(t_stack *stk, int *max_b, int *min_b)
{
	t_list	*actions;

	while (ft_lstsize(stk->stack_a) > 3)
	{
		actions = calculate_moves(stk, max_b, min_b);
		parse_move(stk, actions);
		stk_limits(stk->stack_b, max_b, min_b);
		ft_lstclear(&actions, (void *) ft_delete);
	}
	sort_3(stk);
	while (ft_lstsize(stk->stack_b) > 0)
		push_back(stk);
	rotate_finish(stk);
}

void	init_sort(t_stack *stk)
{
	int	max_b;
	int	min_b;
	int	*tmp;

	if (finish_check(stk) < 1)
	{
		push_b(stk);
		tmp = stk->stack_b->content;
		max_b = *tmp;
		min_b = *tmp;
			if (ft_lstsize(stk->stack_a) > 3)
		{
			push_b(stk);
			stk_limits(stk->stack_b, &max_b, &min_b);
			start_move(stk, &max_b, &min_b);
		}
		else if (ft_lstsize(stk->stack_a) > 0)
		{
			sort_3(stk);
			push_back(stk);
			rotate_finish(stk);
		}
	}
	tmp = NULL;
	return ;
}
