/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:53:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/18 13:55:01 by ffornes-         ###   ########.fr       */
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
	int		i;

	i = 2;
	out = input[1];
	while (input[i])
	{
		input[i] = check_zeros(input[i]);
		out = ft_strjoin(out, " ");
		out = ft_strjoin(out, input[i++]);
	}
	ft_printf(GREEN"OK: "WHITE"Input joined successfully: "YELLOW"%s\n"WHITE, out);
	return (out);
}

static t_list	*convert_to_tlist(char **input)
{
	int		i;
	int		n;
	int		*k;
	t_list	*lst;
	t_list	*stack;

	i = 0;
	while (input[i]) // Not checking if number is valid int atm
	{
		input[i] = check_zeros(input[i]);
		k = malloc(sizeof(int *));
		n = ft_atoi(input[i]);
		*k = n;
		if (n || input[i][0] == '0')
		{
			if (i == 0)
				stack = ft_lstnew(k);
			else
			{
				lst = ft_lstnew(k);
				ft_lstadd_back(&stack, lst);
			}
		}
		else	// Must free remains of *OUT && all allocated *STACK
		{
			ft_printf(RED"Error: "WHITE"Found a number that isn't an integer\n");
			exit(1);
		}
		i++;
	}
	return (stack);
}

t_list	*parse(char **str)
{
	char	**out;
	char	*input;
	t_list	*stack;
	int		i;

	i = 0;
	input = join_input(str);
	if (check_digits(input) < 1)
		return (NULL);
	out = ft_split(input, ' ');
	if (!out)
		return (NULL);
	ft_printf(GREEN"OK: "WHITE"Input splitted successfully\n");
	stack = convert_to_tlist(out);
	if (check_duplicates(&stack) < 1)
		return (NULL);
	check_contents(&stack);
	return (stack);
}
