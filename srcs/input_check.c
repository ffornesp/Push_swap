/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:00:42 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/17 15:34:47 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_duplicates(t_list **stack)
{
	t_list	*aux;
	t_list	*n;

	aux = *stack;
	n = aux;
	aux = aux->next;
	while (aux->next)
	{
		if (n->content == aux->content)
		{
			ft_printf("Error, found duplicate values in input\n");	
			return (0);
		}
		else if (aux->next)
			aux = aux->next;
		else
		{
			n = n->next;
			aux = n->next; // Check this cause maybe u loose somethings bb
		}
	}
	return (1);
}

int	check_digits(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		if (ft_isdigit(*(str + i)) || *(str + i) == ' ' 
			|| ((*(str + i) == '-') && ft_isdigit(*(str + i + 1))))
			i++;
		else
		{
			ft_printf("Error, input is invalid\n");
			free(str);
			return (0);
		}
	}
	ft_printf("The input chars are valid\n");
	return (1);
}
