/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:53:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/18 17:38:49 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	check_contents(t_list **stack) // Temp function for testing purposes
{
	t_list	*aux;
	int		*i;

	aux = *stack;
	ft_printf("Checking contents of stack...\n");
	while (aux)
	{
		i = aux->content;
		ft_printf("%d\n", *i);
		aux = aux->next;
	}
}

static char	*join_input(char **input)
{
	char	*out;
	char	*aux;
	int		i;

	i = 2;
	out = input[1];
	aux = NULL;
	while (input[i])
	{
		if (aux)
			free(aux);
		input[i] = check_zeros(input[i]);
		out = ft_strjoin(out, " ");
		aux = out;
		out = ft_strjoin(out, input[i]);
		free(aux);
		aux = out;
		i++;
	}
	//ft_printf(GREEN"OK: "WHITE"Input joined successfully: "YELLOW"%s\n"WHITE, out);
	return (out);
}

static t_list	*convert_to_tlist(char **input)
{
	int		i;
	int		n;
	int		*k;
	t_list	*stack;

	i = 0;
	while (input[i]) // Not checking if number is valid int atm
	{
		input[i] = check_zeros(input[i]);
		k = malloc(sizeof(int *));
		n = ft_atoi(input[i]);
		*k = n;
		if (n || input[i][0] == '0')
			ft_lstadd_back(&stack, ft_lstnew(k));
		else
		{
			//ft_printf(RED"Error: "WHITE"Found a number that isn't an integer\n");
			while (input[i])
				free(input[i++]);
			ft_lstclear(&stack, (void *)ft_delete);
			exit(1); 
		}
		free(input[i]);
		i++;
	}
	free(input);
	return (stack);
}

t_list	*parse(char **str)
{
	char	**out;
	char	*input;
	t_list	*stack;

	input = join_input(str);
	if (check_digits(input) < 1)
	{
		ft_printf(RED"ERROR: "WHITE"Found invalid chars in input\n");
		return (NULL);
	}
	ft_printf(GREEN"OK: "WHITE"Input is valid\n");
	out = ft_split(input, ' ');
	if (!out)
		return (NULL);
	free(input);
	stack = convert_to_tlist(out);
	if (check_duplicates(stack) < 1)
	{
		ft_printf(RED"ERROR: "WHITE"Found duplicate numbers\n");
		return (NULL);
	}
	ft_printf(GREEN"OK: "WHITE"No duplicates were found\n");
	check_contents(&stack);
	return (stack);
}
