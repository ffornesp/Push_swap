/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 19:41:52 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_move(m_stack *stk, int *max_b, int *min_b)
{
	c_action	*actions;
	char		**tmp;

	actions = malloc(sizeof(c_action));
	actions->amount = malloc(sizeof(int));
	actions->moves = ft_strdup("");
	while (ft_lstsize(stk->stack_a) > 3)
	{
		actions = calculate_moves(stk, max_b, min_b);
		break ;
		//tmp = ft_split(actions->moves, '\n');
		//parse_move(stk, tmp);
		//stk_limits(stk->stack_b, max_b, min_b);
	}
	tmp = NULL;
	//free(actions);
	// Push_back(stk);
}

void	init_sort(m_stack *stk)
{
	int	max_b;
	int	min_b;
	int	*tmp;

	push_b(stk);
	ft_printf("pb\n");
	tmp = stk->stack_b->content;
	max_b = *tmp;
	min_b = *tmp;
	if (ft_lstsize(stk->stack_a) > 3)
	{
		push_b(stk);
		ft_printf("pb\n");
		stk_limits(stk->stack_b, &max_b, &min_b);
		
		ft_printf(YELLOW"  STACK: A\n"WHITE);
		check_contents(stk->stack_a);
		ft_printf(YELLOW"  STACK: B\n"WHITE);
		check_contents(stk->stack_b);
		
		start_move(stk, &max_b, &min_b);
	}
	else if (ft_lstsize(stk->stack_a) > 0)
	{
		sort_3(stk);
		// Push_back(stk);
	}
	tmp = NULL;
	return ;
}
