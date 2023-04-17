/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:53:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/17 15:34:43 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static char	*join_input(char **input)
{
	char	*out;
	int		i;

	i = 2;
	out = input[1];
	while (input[i])
	{
		out = ft_strjoin(out, " ");
		out = ft_strjoin(out, input[i++]);
	}
	ft_printf("Input joined successfully\n%s\n", out);
	return (out);
}

static t_list	*save_input(char **input)
{
	int		i;
	int		n;
	t_list	*stack;
	t_list	*lst;

	i = 0;
	while (input[i])
	{
		n = ft_atoi(input[i]);
		if (n || input[i][0] == '0')
		{
			if (i == 0)
				stack = ft_lstnew(n);
			else
			{
				lst = ft_lstnew(n);
				ft_lstadd_back(&stack, lst);
			}
			free(input[i]);
		}
		else
		{
			// Must free remains of *OUT && all allocated *STACK
			ft_printf("Error, found a number that isn't an integer\n");
		}
		i++;
	}
	return (stack);
}

t_list	**parse(char **str)
{
	char	**out;
	char	*input;
	t_list	*stack;
	int		i;

	i = 0;
	input = join_input(str);
	if (check_digits(input) > 0)
	{
		out = ft_split(input, ' ');
		if (!out)
			return (NULL);
		while (out[i])
		{	
			i++;
			ft_printf("%s\n", out++);
		}
		/*
		stack = save_input(out);
		if (check_duplicates(&stack) > 0)
			ft_printf("Parse was successful\n");
		else
			//ft_lstfree(&stack);
		return (&stack);
		*/
	}
	return (NULL);
}
