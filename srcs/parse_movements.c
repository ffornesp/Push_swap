/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 13:06:36 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "action_defs.h"

void	parse_move(t_stack *stk, t_list *actions)
{
	t_list	*aux;
	int		*act;

	aux = actions;
	while (aux)
	{
		act = aux->content;
		if (*act == PUSH_A)
			push_a(stk, 1);
		else if (*act == PUSH_B)
			push_b(stk, 1);
		else if (*act == ROTATE_A)
			rotate_a(stk, 1);
		else if (*act == ROTATE_B)
			rotate_b(stk, 1);
		else if (*act == ROTATE_R)
			rotate_r(stk, 1);
		else if (*act == REV_ROTATE_A)
			reverse_rotate_a(stk, 1);
		else if (*act == REV_ROTATE_B)
			reverse_rotate_b(stk, 1);
		else if (*act == REV_ROTATE_R)
			reverse_rotate_r(stk, 1);
		aux = aux->next;
	}
}
