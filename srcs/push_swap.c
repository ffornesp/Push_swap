/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:33:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 13:28:16 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char	**str)
{
	m_stack	*stk;

	stk = malloc(sizeof(m_stack));
	stk->stack_a = parse(str);
	stk->stack_b = NULL;

	//swap_a(stk);
	push_b(stk);
	ft_printf(YELLOW"  STACK A: \n"WHITE);
	check_contents(stk->stack_a);
	ft_printf(YELLOW"  STACK B: \n"WHITE);
	check_contents(stk->stack_b);
	ft_lstclear(&stk->stack_a, (void *)ft_delete);
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
