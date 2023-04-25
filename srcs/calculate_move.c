/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/25 10:24:33 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_this(t_list *lst)
{
	t_list	*aux;
	int		*c;

	aux = lst;
	ft_printf("Actions content:\t");
	while (aux)
	{
		c = aux->content;
		if (c)
			ft_printf("%c", *c);
		aux = aux->next;
	}
	ft_printf("\n");
}

static int 	*find_p(int n, t_list *lst)
{
	t_list	*aux;
	int		*i;
	int		*target;

	aux = lst;
	target = NULL;
	while (aux)
	{
		i = aux->content;
		if (!target && *i > n)
			target = i;
		if (*i > n && *i < *target)
			target = i;
		aux = aux->next;
	}
	return (target);
}

t_list	*calculate_moves(m_stack *stk, int *max_b, int *min_b)
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
		ft_printf(YELLOW"Checking %d\n"WHITE, *i);
		if (*i > *max_b || *i < *min_b)
		{
			calc_rot(stk->stack_b, max_b, 1, &tmp_act);
			calc_rot(stk->stack_a, i, 0, &tmp_act);
			check_this(tmp_act);
			check_merge_rotation(&tmp_act);
			add_push(&tmp_act, 0);
			check_this(tmp_act);

		}
		else
		{
			calc_rot(stk->stack_b, find_p(*i, stk->stack_b), 1, &tmp_act);
			calc_rot(stk->stack_a, i, 0, &tmp_act);
			check_this(tmp_act);
			check_merge_rotation(&tmp_act);
			add_push(&tmp_act, 0);
			check_this(tmp_act);
		}
		if (!cheapest_action)
			cheapest_action = tmp_act;
		else if (ft_lstsize(cheapest_action) > ft_lstsize(tmp_act))
		{
			ft_lstclear(&cheapest_action, (void *)ft_delete);
			cheapest_action = tmp_act;
		}
		aux = aux->next;
	}
	ft_printf(GREEN"Found cheapest move: %d moves\n"WHITE, ft_lstsize(cheapest_action));
	return (cheapest_action);
}
