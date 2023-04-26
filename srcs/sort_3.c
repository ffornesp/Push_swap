/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:18:12 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 10:08:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(m_stack *stk)
{
	int		*i;
	int		*j;
	int		*k;

	while (finish_check(stk) < 1)
	{
		if (ft_lstsize(stk->stack_a) < 3)
			swap_a(stk, 0);
		else
		{
			i = stk->stack_a->content;
			j = stk->stack_a->next->content;
			k = stk->stack_a->next->next->content;
			if (*j > *i && *j > *k)
				reverse_rotate_a(stk, 0);
			else if (*i > *j && *i > *k)
				rotate_a(stk, 0);
			else if (*i > *j && *i < *k)
				swap_a(stk, 0);
		}
	}
	return ;
}
