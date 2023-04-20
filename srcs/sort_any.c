/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 17:35:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_move(m_stack *stk, int *max_b, int *min_b)
{
	c_action	*actions;
	char		**tmp;

	actions = malloc(sizeof(c_action));
	actions->amount = malloc(sizeof(int));
	actions->amount = 0;
	actions->moves = ft_strdup("");
	while (ft_lstsize(stk->stack_a) > 3)
	{
		actions = calculate_moves(stk, max_b, min_b);
		tmp = ft_split(actions->moves, '\n');
		parse_move(stk, tmp);
		stk_limits(stk->stack_b, max_b, min_b);
	}
	free(actions->moves);
	free(actions->amount);
	free(actions);
	// Push_back(stk);
}

void	init_sort(m_stack *stk)
{
	int	*max_b;
	int	*min_b;
	int	*tmp;

	push_b(stk);
	ft_printf("pb\n");
	max_b = stk->stack_b->content;
	min_b = max_b;
	if (ft_lstsize(stk->stack_a) > 3)
	{
		push_b(stk);
		ft_printf("pb\n");
		stk_limits(stk->stack_b, max_b, min_b);
		start_move(stk, max_b, min_b);
	}
	else
	{
		sort_3(stk);
		// Push_back(stk);
	}
	tmp = NULL;
	return ;
}
