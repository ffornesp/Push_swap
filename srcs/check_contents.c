/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_contents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 09:48:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 09:51:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack(m_stack *stk)
{
	ft_printf(YELLOW"  STACK: A\n"WHITE);
	check_list(stk->stack_a);
	ft_printf(YELLOW"  STACK: B\n"WHITE);
	check_list(stk->stack_b);

	return ;
}

void	check_list(t_list *stack)
{
	t_list	*aux;
	int		*i;

	aux = stack;
	while (aux)
	{
		i = aux->content;
		ft_printf("      %d\n", *i);
		aux = aux->next;
	}
	ft_printf(WHITE);
}
