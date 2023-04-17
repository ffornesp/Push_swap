/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:53:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/17 15:53:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_list	*save_as_tlist(char **input)
{
	int		i;
	int		n;
	t_list	*lst;
	t_list	*stack;

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
		else	// Must free remains of *OUT && all allocated *STACK
			ft_printf("Error, found a number that isn't an integer\n");
		i++;
	}
	return (stack);
}

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

static void	check_contents(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	ft_printf("Checking contents of stack...\n");
	while (aux)
	{
		ft_printf("%d\n", aux->content);
		aux = aux->next;
	}
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
		free(input);
		if (!out)
			return (NULL);
		ft_printf("Input splitted successfully\n");
		stack = save_as_tlist(out);
		check_contents(&stack);
		/*
		if (check_duplicates(&stack) > 0)
			ft_printf("Parse was successful\n");
		else
			//ft_lstfree(&stack);
		return (&stack);
		*/
	}
	return (NULL);
}
