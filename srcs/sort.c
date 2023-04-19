/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:18:12 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 17:48:37 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_little(m_stack *stk)
{
	int		*i;
	int		*j;
	int		*k;
	t_list	*aux;

	aux = stk->stack_a;
	while (finish_check(stk) < 1)
	{
		i = stk->stack_a->content;
		j = stk->stack_a->next->content;
		k = stk->stack_a->next->next->content;
		if (*j > *i && *j > *k)
			reverse_rotate_a(stk);
		else if (*i > *j && *i > *k)
			rotate_a(stk);
		else if (*i > *j && *i < *k)
			swap_a(stk);
		ft_printf("CHECK MOV: \n");
		check_contents(stk->stack_a);
	}
	return ;
}
