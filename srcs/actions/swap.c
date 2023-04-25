/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:44:12 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/25 13:13:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*swap(t_list *stack)
{
	t_list	*aux;
	t_list	*first;
	t_list	*second;

	first = stack;
	second = stack->next;
	aux = NULL;
	if (second->next)
		aux = second->next;
	first->next = NULL;
	second->next = NULL;
	ft_lstadd_front(&aux, first);
	ft_lstadd_front(&aux, second);
	return (aux);
}

void	swap_a(m_stack *stk, int check)
{
	stk->stack_a = swap(stk->stack_a);
	if (check < 1)
		ft_printf("sa\n");
}

void	swap_b(m_stack *stk, int check)
{
	stk->stack_b = swap(stk->stack_b);
	if (check < 1)
		ft_printf("sb\n");
}

void	swap_s(m_stack *stk)
{
	swap_a(stk, 1);
	swap_b(stk, 1);
	ft_printf("ss\n");
}
