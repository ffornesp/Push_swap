/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:53:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:16:00 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse(char *str, t_list **stack_a)
{
	char	**out;

	if (check_input(str, stack_a))
	{
		out = ft_split(str, ' ');
		if (!out)
			// exit
		// Fill t_list
		while (out[i])
		{
			n = ft_atoi(out[i]);
			if (n || *out[i] == '0')
			{
				ft_lstadd_back(stack_a, ft_lstnew(n));
				free(out[i]);
			}
			else
			{
				// stderror
			}
			i++;
		}
		// Check_input2();
		// DoStuff
		check_input2(&stack_a)
	}
	return ; //exit
}

static void	check_input2(t_list **stack_a);
{
	int	n;

	n = stack_a->value;
	while (stack_a->next)
	{
		if (n == stack_a
	}
}

static char	**check_input1(char *str, t_list **stack_a)
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
			// stderror
			return (0);
		}
	}
	return (1);
}
