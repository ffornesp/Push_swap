/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:03:17 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 13:21:45 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(m_stack *stk)
{
	t_list	*lst;

	lst = stk->stack_b;
	stk->stack_b = stk->stack_b->next;
	lst->next = NULL;
	ft_lstadd_front(&stk->stack_a, lst);
}

void	push_b(m_stack *stk)
{
	t_list	*lst;

	lst = stk->stack_a;
	stk->stack_a = stk->stack_a->next;
	lst->next = NULL;
	ft_lstadd_front(&stk->stack_b, lst);
}
