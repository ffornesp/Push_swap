/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:00:42 by ffornes-          #+#    #+#             */
/*   Updated: 2023/06/26 18:45:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

char	*check_zeros(char *input)
{
	char	c;

	while (*input == ' ')
		input++;
	if ((input[0] == '-' || input[0] == '+') && input[1] == '0')
	{
		c = input[0];
		while (*(input + 1) == '0' && *(input + 2))
			input++;
		if (c == '+')
			input++;
		else if (input[1] != '0')
			input[0] = c;
		else
			input[0] = '0';
	}
	else if (input[0] == '0')
		while (input[0] == '0' && input[1] != '\0')
			input++;
	return (input);
}

int	check_duplicates(t_list *stack)
{
	t_list	*aux;
	t_list	*current;
	int		*j;

	current = stack;
	aux = current->next;
	while (aux)
	{
		j = aux->content;
		if (*(int *)current->content == *j)
			return (0);
		if (aux->next)
			aux = aux->next;
		else if (current->next)
		{
			current = current->next;
			aux = current->next;
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
		if (i > 0 && ft_isdigit(*(str + i - 1))
			&& (*(str + i) == '-' || (*(str + i) == '+')))
			return (0);
		else if (ft_isdigit(*(str + i)) || *(str + i) == ' '
			|| ((*(str + i) == '-') && ft_isdigit(*(str + i + 1)))
			|| ((*(str + i) == '+') && ft_isdigit(*(str + i + 1))))
			i++;
		else
			return (0);
	}
	return (1);
}

static int	check_limits(long j)
{
	int	i;

	if (j > INT_MAX || j < INT_MIN)
		return (0);
	else
	{
		i = (int)j;
		return (i);
	}
}

int	ft_atol(const char *str)
{
	int		i;
	long	j;

	i = 0;
	j = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i++;
		if (*(str + 1) == '+' || *(str + 1) == '-')
			return (0);
		str++;
	}
	while (ft_isdigit(*str))
	{
		j = (j * 10) + (*str - '0');
		str++;
	}
	if (i > 0)
		j *= -1;
	return (check_limits(j));
}
