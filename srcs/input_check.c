/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:00:42 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/18 16:48:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*check_zeros(char *input)
{
	char	c;

	if ((input[0] == '-' || input[0] == '+') && input[1] == '0')
	{
		c = input[0];
		while (*(input + 1) == '0')
			input++;
		if (c == '+')
			input++;
		else
			input[0] = c;
	}
	return (input);
}

int	check_duplicates(t_list *stack) // May need optimization, maybe access **stack directly with i j
{
	t_list	*aux;
	t_list	*current;
	int		*i;
	int		*j;

	current = stack;
	aux = current->next;
	while (aux)
	{
		i = current->content;
		j = aux->content;
		if (*i == *j)
		{
			//ft_printf(RED"ERROR: "WHITE"Found the number %d twice\n", *i);
			return (0);
		}
		if (aux->next)
			aux = aux->next;
		else if (current->next) // Next aux is NULL so...
		{
			current = current->next;
			aux = current->next;
		}
	}
	//ft_printf(GREEN"OK: "WHITE"No duplicate numbers found in input...\n"GREEN"\tPARSE SUCCESSFUL\n"WHITE);
	return (1);
}

int	check_digits(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		if (ft_isdigit(*(str + i)) || *(str + i) == ' ' 
			|| ((*(str + i) == '-') && ft_isdigit(*(str + i + 1)))
			|| ((*(str + i) == '+') && ft_isdigit(*(str + i + 1))))
			i++;
		else
		{
			//ft_printf(RED"ERROR: "WHITE"Input is invalid\n");
			free(str);
			return (0);
		}
	}
	//ft_printf(GREEN"OK: "WHITE"Input chars are valid\n");
	return (1);
}
