/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 17:09:17 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_finish(t_stack *stk)
{
	int		*limits;
	int		size;
	t_list	*aux;

	limits = NULL;
	aux = stk->stack_a;
	limits = stk_limits(aux);
	size = ft_lstsize(stk->stack_a) / 2;
	while (finish_check(stk) < 1)
	{
		if (ft_lstpos(stk->stack_a, &limits[0]) < size)
			rotate_a(stk, 0);
		else if (ft_lstpos(stk->stack_a, &limits[0]) >= size)
			reverse_rotate_a(stk, 0);
	}
	free(limits);
}

static void	push_back(t_stack *stk)
{
	t_list	*actions;
	int		*limits;

	limits = stk_limits(stk->stack_a);
	actions = calculate_moves(stk, limits, 1);
	parse_move(stk, actions);
	ft_lstclear(&actions, (void *) ft_delete);
	free(limits);
}

static void	start_move(t_stack *stk)
{
	t_list	*actions;
	int		*limits;

	while (ft_lstsize(stk->stack_a) > 3)
	{
		limits = stk_limits(stk->stack_b);
		actions = calculate_moves(stk, limits, 0);
		parse_move(stk, actions);
		limits = stk_limits(stk->stack_b);
		ft_lstclear(&actions, (void *) ft_delete);
		free(limits);
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
		if (ft_lstsize(stk->stack_a) > 3)
		{
			push_b(stk);
			limits = stk_limits(stk->stack_b);
			start_move(stk);
			free(limits);
		}
		else if (ft_lstsize(stk->stack_a) > 0)
		{
			sort_3(stk);
			push_back(stk);
			rotate_finish(stk);
		}
	}
	return ;
}
