/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 17:39:29 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	min_max_change_check(int *i, int *max, int *min)
{
	if (*i > *max)
		max = i;
	else if (*i < *min)
		min = i;
}

static void	cost_check(c_action *cheapest, c_action *tmp)
{
	if (!cheapest)
		cheapest = tmp;
	else if (cheapest->amount > tmp->amount)
	{
		free(cheapest->amount);
		free(cheapest->moves);
		free(cheapest);
		cheapest = tmp;
	}
	else
	{
		free(tmp->amount);
		free(tmp->moves);
		free(tmp);
	}
}

c_action	*calculate_moves(m_stack *stk, int *max_b, int *min_b)
{
	c_action	*cheapest;
	c_action	*tmp;
	int			*i;

	cheapest = NULL;
	while (stk->stack_a->next)
	{
		i = stk->stack_a->content;
		if (*i > *max_b || *i < *min_b)
		{
			tmp = calculate_rotation(stk->stack_b, max_b, 1);
			tmp = calculate_rotation(stk->stack_a, i, 0);
			merge_rot_check(tmp);
			add_to_moves(tmp, 1, "pb\n");
		}
		else
		{
			// Rotate b until I can push lst between [> lst >]
		}
		cost_check(cheapest, tmp);
		stk->stack_a = stk->stack_a->next;
	}
	min_max_change_check(stk->stack_b->content, max_b, min_b);
	return (cheapest);
}
