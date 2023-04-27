/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 14:55:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 12:55:50 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "push_swap.h"

void	rotate_a(t_stack *stk, int print)
{
	t_list	*aux;
	t_list	*f;

	aux = stk->stack_a;
	stk->stack_a = stk->stack_a->next;
	f = ft_lstlast(stk->stack_a);
	aux->next = NULL;
	f->next = aux;
	if (print > 0)
		ft_printf("ra\n");
}

void	rotate_b(t_stack *stk, int print)
{
	t_list	*aux;
	t_list	*f;

	aux = stk->stack_b;
	stk->stack_b = stk->stack_b->next;
	f = ft_lstlast(stk->stack_b);
	aux->next = NULL;
	f->next = aux;
	if (print > 0)
		ft_printf("rb\n");
}

void	rotate_r(t_stack *stk, int print)
{
	rotate_a(stk, 0);
	rotate_b(stk, 0);
	if (print > 0)
		ft_printf("rr\n");
}
