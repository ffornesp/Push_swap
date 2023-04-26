/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 16:12:22 by ffornes-         ###   ########.fr       */
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
	t_list	*actions;
	int		*limits;

	limits = malloc(sizeof(int) * 2);
	limits[0] = *(int *)stk->stack_a->content;
	limits[1] = *(int *)stk->stack_a->content;
	stk_limits(stk->stack_a, &limits[1], &limits[0]);
	actions = calculate_moves(stk, limits, 1);
	parse_move(stk, actions);
	ft_lstclear(&actions, (void *) ft_delete);
	free(limits);
}

static void	start_move(t_stack *stk, int *limits)
{
	t_list	*actions;

	while (ft_lstsize(stk->stack_a) > 3)
	{
		actions = calculate_moves(stk, limits, 0);
		parse_move(stk, actions);
		stk_limits(stk->stack_b, &limits[1], &limits[0]);
		ft_lstclear(&actions, (void *) ft_delete);
	}
	sort_3(stk);
	while (ft_lstsize(stk->stack_b) > 0)
		push_back(stk);
	rotate_finish(stk);
}

void	init_sort(t_stack *stk)
{
	int	*limits;

	if (finish_check(stk) < 1)
	{
		push_b(stk);
		limits = malloc(sizeof(int) * 2);
		limits[0] = *(int *)stk->stack_b->content;
		limits[1] = *(int *)stk->stack_b->content;
		if (ft_lstsize(stk->stack_a) > 3)
		{
			push_b(stk);
			stk_limits(stk->stack_b, &limits[1], &limits[0]);
			start_move(stk, limits);
		}
		else if (ft_lstsize(stk->stack_a) > 0)
		{
			sort_3(stk);
			push_back(stk);
			rotate_finish(stk);
		}
		free(limits);
	}
	return ;
}
