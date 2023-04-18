/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:33:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/18 12:15:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		*lst = aux->next;
		free(aux);
		aux = *lst;
	}
	*lst = NULL;
}

void	push_swap(char	**str)
{
	parse(str);
	
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		push_swap(argv);
	}
	else
		ft_printf("An input is required to run the program\n");
	return (0);
}
