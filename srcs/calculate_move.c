/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/25 17:46:53 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// There's error in phase 0 where it calculates it so fucking wrong it's
// laughable
static int 	*find_p(int n, t_list *lst, int phase)
{
	t_list	*aux;
	int		*i;
	int		*target;

	aux = lst;
	target = NULL;
	while (aux)
	{
		i = aux->content;
		if (!target)
		{
			if ((phase == 0 && *i < n) || (phase == 1 && *i > n))
				target = i;
		}
		else
		{
			if ((phase == 0 && *i < n && *i > *target)
			|| (phase == 1 && *i > n && *i < *target))
				target = i;
		}
		aux = aux->next;
	}
	return (target);
}

static t_list	*get_cheapest(t_list *tmp_act, t_list *cheapest_act, int stack)
{
	if (ft_lstsize(tmp_act) > 1)
		check_merge_rotation(&tmp_act);
	add_push(&tmp_act, stack);
	if (!cheapest_act)
		cheapest_act = tmp_act;
	else if (ft_lstsize(cheapest_act) > ft_lstsize(tmp_act))
	{
		ft_lstclear(&cheapest_act, (void *)ft_delete);
		cheapest_act = tmp_act;
	}
	return (cheapest_act);
}

t_list	*calculate_push_back(m_stack *stk, int *max, int *min)
{
	t_list	*cheapest_action;
	t_list	*tmp_act;
	t_list	*aux;
	int		*i;

	aux = stk->stack_b;
	cheapest_action = NULL;
	while (aux)
	{
		tmp_act = ft_lstnew(NULL);
		i = aux->content;
		if (*i > *max || *i < *min)
		{
			calc_rot(stk->stack_a, min, 0, &tmp_act);
			calc_rot(stk->stack_b, i, 1, &tmp_act);
		}
		else
		{
			calc_rot(stk->stack_a, find_p(*i, stk->stack_a, 1), 0, &tmp_act);
			calc_rot(stk->stack_b, i, 1, &tmp_act);
		}
		cheapest_action = get_cheapest(tmp_act, cheapest_action, 1);
		aux = aux->next;
	}
	return (cheapest_action);
}

t_list	*calculate_moves(m_stack *stk, int *max, int *min)
{
	t_list	*cheapest_action;
	t_list	*tmp_act;
	t_list	*aux;
	int		*i;

	aux = stk->stack_a;
	cheapest_action = NULL;
	while (aux)
	{
		tmp_act = ft_lstnew(NULL);
		i = aux->content;
		if (*i > *max || *i < *min)
		{
			calc_rot(stk->stack_b, max, 1, &tmp_act);
			calc_rot(stk->stack_a, i, 0, &tmp_act);
		}
		else
		{
			calc_rot(stk->stack_b, find_p(*i, stk->stack_b, 0), 1, &tmp_act);
			calc_rot(stk->stack_a, i, 0, &tmp_act);
		}
		cheapest_action = get_cheapest(tmp_act, cheapest_action, 0);
		aux = aux->next;
	}
	return (cheapest_action);
}
