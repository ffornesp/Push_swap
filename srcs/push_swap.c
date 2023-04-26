/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:33:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 10:08:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char	**str)
{
	int		size;
	m_stack	*stk;

	stk = malloc(sizeof(m_stack));
	stk->stack_a = parse(str);
	stk->stack_b = NULL;
	size = ft_lstsize(stk->stack_a);
	if (size > 1 && size <= 3)
		sort_3(stk);
	else
		init_sort(stk);
	ft_lstclear(&stk->stack_a, (void *)ft_delete);
	ft_lstclear(&stk->stack_b, (void *)ft_delete);
	free(stk);
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
		push_swap(argv);
	else
		ft_printf(YELLOW"WARNING: "WHITE"An input is required to run the program\n");
	return (0);
}
