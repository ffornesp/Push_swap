/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 12:24:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*find_p(int n, t_list *lst, int phase)
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
	else
		ft_lstclear(&tmp_act, (void *)ft_delete);
	return (cheapest_act);
}

static t_list	*get_temp(t_stack *stk, int *aux, int *limits, int id)
{
	t_list	*tmp;

	tmp = ft_lstnew(NULL);
	if (id == 0 && (*aux > limits[1] || *aux < limits[0]))
	{
		calc_rot(stk->stack_b, &limits[1], 1, &tmp);
		calc_rot(stk->stack_a, aux, 0, &tmp);
	}
	else if (id == 0)
	{
		calc_rot(stk->stack_b, find_p(*aux, stk->stack_b, 0), 1, &tmp);
		calc_rot(stk->stack_a, aux, 0, &tmp);
	}
	else if (id == 1 && (*aux > limits[1] || *aux < limits[0]))
	{
		calc_rot(stk->stack_a, &limits[0], 0, &tmp);
		calc_rot(stk->stack_b, aux, 1, &tmp);
	}
	else if (id == 1)
	{
		calc_rot(stk->stack_a, find_p(*aux, stk->stack_a, 1), 0, &tmp);
		calc_rot(stk->stack_b, aux, 1, &tmp);
	}
	return (tmp);
}

t_list	*calculate_moves(t_stack *stk, int *limits, int id)
{
	t_list	*cheapest_action;
	t_list	*tmp;
	t_list	*aux;

	aux = stk->stack_a;
	if (id == 1)
		aux = stk->stack_b;
	cheapest_action = NULL;
	while (aux)
	{
		tmp = get_temp(stk, aux->content, limits, id);
		cheapest_action = get_cheapest(tmp, cheapest_action, id);
		aux = aux->next;
	}
	return (cheapest_action);
}
