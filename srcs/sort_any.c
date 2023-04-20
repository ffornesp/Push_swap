/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_any.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 10:48:57 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	start_move(m_stack *stk, int *max_b, int *min_b)
{
	while (ft_lstsize(stk->stack_a) > 3)
	{
		max_b = NULL;
		min_b = NULL;		
	}
}

void	init_sort(m_stack *stk)
{
	int	*max_b;
	int	*min_b;
	int	*tmp;

	push_b(stk);
	max_b = stk->stack_b->content;
	min_b = max_b;
	push_b(stk);
	tmp = stk->stack_b->content;
	if (*tmp > *max_b)
		max_b = tmp;
	else if (*tmp < *min_b)
		min_b = tmp;
	tmp = NULL;
	start_move(stk, max_b, min_b);
}
