/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:44:12 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 11:44:46 by ffornes-         ###   ########.fr       */
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

void	swap_a(t_stack *stk, int print)
{
	stk->stack_a = swap(stk->stack_a);
	if (print > 0)
		ft_printf("sa\n");
}

void	swap_b(t_stack *stk, int print)
{
	stk->stack_b = swap(stk->stack_b);
	if (print > 0)
		ft_printf("sb\n");
}

void	swap_s(t_stack *stk, int print)
{
	swap_a(stk, 0);
	swap_b(stk, 0);
	if (print > 0)
		ft_printf("ss\n");
}
