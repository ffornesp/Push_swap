/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:03:17 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 11:42:35 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *stk, int print)
{
	t_list	*lst;

	lst = stk->stack_b;
	stk->stack_b = stk->stack_b->next;
	lst->next = NULL;
	ft_lstadd_front(&stk->stack_a, lst);
	if (print > 0)
		ft_printf("pa\n");
}

void	push_b(t_stack *stk, int print)
{
	t_list	*lst;

	lst = stk->stack_a;
	stk->stack_a = stk->stack_a->next;
	lst->next = NULL;
	ft_lstadd_front(&stk->stack_b, lst);
	if (print > 0)
		ft_printf("pb\n");
}
