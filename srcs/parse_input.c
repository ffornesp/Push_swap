/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:53:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 09:51:39 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_input(char **input)
{
	char	*out;
	char	*aux;
	int		i;

	i = 2;
	out = malloc(sizeof(char *) * (ft_strlen(input[1]) + 1));
	ft_strlcpy(out, input[1], ft_strlen(input[1]) + 1);
	while (input[i])
	{
		aux = out;
		input[i] = check_zeros(input[i]);
		out = ft_strjoin(out, " ");
		free(aux);
		aux = out;
		out = ft_strjoin(out, input[i]);
		free(aux);
		aux = out;
		i++;
	}
	return (out);
}

static t_list	*convert_to_tlist(char **input)
{
	int		i;
	int		*k;
	t_list	*stack;

	i = 0;
	stack = NULL;
	while (input[i])
	{
		k = malloc(sizeof(int));
		*k = ft_atoi(input[i]);
		if (*k || input[i][0] == '0')
			ft_lstadd_back(&stack, ft_lstnew(k));
		else
		{
			while (input[i])
				free(input[i++]);
			ft_lstclear(&stack, (void *)ft_delete);
			exit(1);
		}
		free(input[i]);
		i++;
	}
	return (stack);
}

t_list	*parse(char **str)
{
	char	**out;
	char	*input;
	t_list	*stack;

	input = join_input(str);
	if (check_digits(input) < 1)
		return (NULL);
	out = ft_split(input, ' ');
	if (!out)
		return (NULL);
	free(input);
	stack = convert_to_tlist(out);
	free(out);
	if (check_duplicates(stack) < 1)
		return (NULL);
	ft_printf(YELLOW"  STACK O:\n"GREEN);
	check_list(stack);
	return (stack);
}
