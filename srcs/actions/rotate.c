/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:55:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/25 13:14:01 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(m_stack *stk, int check)
{
	t_list	*aux;
	t_list	*f;

	aux = stk->stack_a;
	stk->stack_a = stk->stack_a->next;
	f = ft_lstlast(stk->stack_a);
	aux->next = NULL;
	f->next = aux;
	if (check < 1)
		ft_printf("ra\n");
}

void	rotate_b(m_stack *stk, int check)
{
	t_list	*aux;
	t_list	*f;

	aux = stk->stack_b;
	stk->stack_b = stk->stack_b->next;
	f = ft_lstlast(stk->stack_b);
	aux->next = NULL;
	f->next = aux;
	if (check < 1)
		ft_printf("rb\n");
}

void	rotate_r(m_stack *stk)
{
	rotate_a(stk, 1);
	rotate_b(stk, 1);
	ft_printf("rr\n");
}
