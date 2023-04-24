/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 16:43:57 by ffornes-         ###   ########.fr       */
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

t_list	*calculate_moves(m_stack *stk, int *max_b, int *min_b)
{
	t_list	*cheapest_action;
	t_list	*tmp_action;
	t_list	*aux;
	int		*i;

	aux = stk->stack_a;
	cheapest_action = NULL;
	while (aux)
	{
		tmp_action = ft_lstnew(NULL);
		i = aux->content;
		ft_printf(YELLOW"Checking %d\n"WHITE, *i);
		if (*i > *max_b || *i < *min_b)
		{
			calc_rotation(stk->stack_b, max_b, 1, &tmp_action);
			calc_rotation(stk->stack_a, i, 0, &tmp_action);
			check_this(tmp_action);
			check_merge_rotation(&tmp_action);
			check_this(tmp_action);
		}
		else
		{
			// Rotate b until I can push lst between [> lst >]
		}
		if (!cheapest_action)
			cheapest_action = tmp_action;
		else if (ft_lstsize(cheapest_action) > ft_lstsize(tmp_action))
		{
			ft_lstclear(&cheapest_action, (void *)ft_delete);
			cheapest_action = tmp_action;
		}
		aux = aux->next;
	}
	//min_max_change_check(stk->stack_b->content, max_b, min_b);
	ft_printf(GREEN"Found cheapest move: %d moves\n"WHITE, ft_lstsize(cheapest_action));
	return (cheapest_action);
}
