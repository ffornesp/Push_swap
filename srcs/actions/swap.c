/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:44:12 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 10:53:52 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*swap(t_list *stack)
{
	t_list	*aux;
	t_list	*first;
	t_list	*second;

	aux = stack;
	first = aux;
	second = aux->next;
	aux = second->next;
	ft_lstadd_front(&aux, first);
	ft_lstadd_front(&aux, second);
	return (aux);
}

void	swap_a(m_stack *stk)
{
	stk->stack_a = swap(stk->stack_a);
}

void	swap_b(m_stack *stk)
{
	stk->stack_b = swap(stk->stack_b);
}

void	swap_ss(m_stack *stk)
{
	swap_a(stk);
	swap_b(stk);
}
