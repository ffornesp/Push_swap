/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:33:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 11:49:11 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char	**str)
{
	//m_stack	*stk;
	t_list	*stack_a;
	//t_list	*stack_b;

	//stk = malloc(sizeof(m_stack));
	stack_a = parse(str);
	//stack_b = NULL;
	//stk->stack_a = stack_a;
	//stk->stack_b = stack_b;

	ft_lstclear(&stack_a, (void *)ft_delete);
//	swap_a(stk);
	//check_contents(stk->stack_a);
	//ft_lstclear(&stk->stack_a, (void *)ft_delete);
	//free(stk);
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
