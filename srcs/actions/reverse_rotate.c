/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:51 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 15:57:03 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(m_stack *stk)
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
}

void	reverse_rotate_b(m_stack *stk)
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
}

void	reverse_rotate_r(m_stack *stk)
{
	reverse_rotate_a(stk);
	reverse_rotate_b(stk);
}
