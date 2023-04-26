/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 11:32:28 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_move(t_stack *stk, t_list *actions)
{
	t_list	*aux;
	int		*act;

	aux = actions;
	while (aux)
	{
		act = aux->content;
		if (*act == 'B')
			push_a(stk);
		else if (*act == 'F')
			push_b(stk);
		else if (*act == 'C')
			rotate_a(stk, 0);
		else if (*act == 'G')
			rotate_b(stk, 0);
		else if (*act == 'J')
			rotate_r(stk);
		else if (*act == 'D')
			reverse_rotate_a(stk, 0);
		else if (*act == 'H')
			reverse_rotate_b(stk, 0);
		else if (*act == 'K')
			reverse_rotate_r(stk);
		aux = aux->next;
	}
}
