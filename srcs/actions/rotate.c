/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:55:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 15:58:11 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(m_stack *stk)
{
	t_list	*aux;
	t_list	*f;

	aux = stk->stack_a;
	stk->stack_a = stk->stack_a->next;
	f = ft_lstlast(stk->stack_a);
	aux->next = NULL;
	f->next = aux;
}

void	rotate_b(m_stack *stk)
{
	t_list	*aux;
	t_list	*f;

	aux = stk->stack_b;
	stk->stack_b = stk->stack_b->next;
	f = ft_lstlast(stk->stack_b);
	aux->next = NULL;
	f->next = aux;
}

void	rotate_r(m_stack *stk)
{
	rotate_a(stk);
	rotate_b(stk);
}
