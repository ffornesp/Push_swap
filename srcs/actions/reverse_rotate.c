/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:32:51 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 11:38:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack *stk, int check)
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
	if (check < 1)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack *stk, int check)
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
	if (check < 1)
		ft_printf("rrb\n");
}

void	reverse_rotate_r(t_stack *stk)
{
	reverse_rotate_a(stk, 1);
	reverse_rotate_b(stk, 1);
	ft_printf("rrr\n");
}
