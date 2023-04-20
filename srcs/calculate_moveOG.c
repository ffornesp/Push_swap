/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 18:52:59 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	min_max_change_check(int *i, int *max, int *min)
{
	if (*i > *max)
		max = i;
	else if (*i < *min)
		min = i;
}
*/

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
	c_action	*tmp_b;
	c_action	*tmp_a;
	t_list		*aux;
	int			*i;

	cheapest = NULL;
	aux = stk->stack_a;
	while (aux->next)
	{
		i = aux->content;
		if (*i > *max_b || *i < *min_b)
		{
			tmp_b = calculate_rotation(stk->stack_b, max_b, 1, tmp_b->amount);
		ft_printf("MOVES IN TEMP_B:\n%s", tmp_b->moves);
			tmp_a = calculate_rotation(stk->stack_a, i, 0, tmp_b->amount);
		//ft_printf("MOVES IN TEMP_A:\n%s", tmp_a->moves);
			ft_printf(RED"TMP_A AMOUNT OF MOVES:\n%s", tmp_a->amount);
			tmp_a->moves = ft_strjoin(tmp_b->moves, tmp_a->moves);
		//ft_printf(YELLOW"MOVES TOTAL: \n%s"WHITE, tmp_a->moves);
			*tmp_a->amount += *tmp_b->amount;
		//ft_printf(RED"TMP AMOUNT OF MOVES:\n%s", tmp_a->amount);
			//merge_rot_check(tmp_a);
		//ft_printf(GREEN"MOVES AFTER MERGE:\n%s"WHITE, tmp_a->moves);
			add_to_moves(tmp_a, 1, "pb\n");
		}
		else
		{
			// Rotate b until I can push lst between [> lst >]
		}
		cost_check(cheapest, tmp_a);
		aux = aux->next;
	}
	//min_max_change_check(stk->stack_b->content, max_b, min_b);
	ft_printf(GREEN"Found cheapest move\n"WHITE);
	return (cheapest);
}
