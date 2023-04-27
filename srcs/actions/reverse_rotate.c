/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:51 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 11:46:28 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stk, int print)
{
	t_list	*lst;
	t_list	*aux;
	int		i;

	aux = stk->stack_a;
	lst = ft_lstlast(aux);
	i = ft_lstsize(aux);
	while (aux->next && i > 2)
	{
		aux = aux->next;
		i--;
	}
	aux->next = NULL;
	lst->next = stk->stack_a;
	stk->stack_a = lst;
	if (print > 0)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *stk, int print)
{
	t_list	*lst;
	t_list	*aux;
	int		i;

	aux = stk->stack_b;
	lst = ft_lstlast(aux);
	i = ft_lstsize(aux);
	while (aux->next && i > 2)
	{
		aux = aux->next;
		i--;
	}
	aux->next = NULL;
	lst->next = stk->stack_b;
	stk->stack_b = lst;
	if (print > 0)
		ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack *stk, int print)
{
	reverse_rotate_a(stk, 0);
	reverse_rotate_b(stk, 0);
	if (print > 0)
		ft_printf("rrr\n");
}
