/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 12:37:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// I don't allocate tmp_action because it's allocated in calculate rotation
// same goes for cheapest_action, since it will point to the memory address
// of the cheapest seen tmp_action
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
		tmp_action = malloc(sizeof(t_list));
		tmp_action->next = NULL;
		i = aux->content;
		ft_printf(YELLOW"Checking %d\n"WHITE, *i);
		if (*i > *max_b || *i < *min_b)
		{
			tmp_action = calc_rotation(stk->stack_b, max_b, 1, tmp_action);
			ft_printf("Rotation in stack_b calculated\n");
			tmp_action = calc_rotation(stk->stack_a, i, 0, tmp_action);
			ft_printf("Rotation has been calculated\n");
			//merge_rot_check(tmp);
			//add_to_moves(tmp, 1, "pb\n");
		}
		else
		{
			// Rotate b until I can push lst between [> lst >]
		}
		if (!cheapest_action)
			cheapest_action = tmp_action;
		if (ft_lstsize(cheapest_action) > ft_lstsize(tmp_action))
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
