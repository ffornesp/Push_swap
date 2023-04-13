/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:33:07 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/13 17:27:56 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	error_handler(t_list **stack)
{

}

static int	check_input(char *str, t_list **stack_a)
{
	int		i;
	int		n;
	char	**out;

	i = 0;
	while (*(str + i))
	{
		if (ft_isdigit(*(str + i)) || *(str + i) == ' ' 
			|| ((*(str + i) == '-') && ft_isdigit(*(str + i + 1))))
			i++;
		else
			return (0);
	}
	out = ft_split(str, ' ');
	i = 0;
	while (out[i])
	{
		n = ft_atoi(out[i]);
		if (n || *out[i] == '0')
			ft_lstadd_back(stack_a, ft_lstnew(n));
		else
		{
			//error?
			break ;
		}
		i++;
	}
	return (1);
}

void	push_swap(char	*str)
{
	t_list	*stack_a;

	stack_a = (struct t_list*)malloc(sizeof(struct t_list));
	if (!check_input(str, &stack_a))
		ft_printf("Error\n");
	else
	{
		ft_printf("No error\n");
	}
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		push_swap(argv[1]);
	return (0);
}
