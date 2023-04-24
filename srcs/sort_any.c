/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 12:00:08 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_move(m_stack *stk, int *max_b, int *min_b)
{
	t_list	*actions;

	while (ft_lstsize(stk->stack_a) > 3)
	{
		ft_printf("Calculating move...\n");
		actions = calculate_moves(stk, max_b, min_b);
		ft_printf("Calculated move\n");
		break ;
		//tmp = ft_split(actions->moves, '\n');
		//parse_move(stk, tmp);
		//stk_limits(stk->stack_b, max_b, min_b);
	}
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
		
		check_stack(stk);	
		start_move(stk, &max_b, &min_b);
	}
	else if (ft_lstsize(stk->stack_a) > 0)
	{
		ft_printf("Stack A is size 3 now\n");
		sort_3(stk);
		// Push_back(stk);
	}
	tmp = NULL;
	return ;
}
