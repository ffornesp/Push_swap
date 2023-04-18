/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:33:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/18 16:17:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	*ft_delete(void	*p)
{
	free(p);
	p = NULL;;
	return (p);
}

void	push_swap(char	**str)
{
	t_list	*stack_a;

	stack_a = parse(str);
	ft_lstclear(&stack_a, (void *)ft_delete);
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
