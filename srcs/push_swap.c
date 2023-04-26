/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:33:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 11:36:32 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char	**str)
{
	int		size;
	t_stack	*stk;

	stk = malloc(sizeof(t_stack));
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
	return (0);
}
