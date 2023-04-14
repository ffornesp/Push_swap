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

/*	Must convert the input that comes into as
 *	*char to **t_list, and allocate memory for
 *	everything while freeing the char pointers.
 *	*/

void	parse(char **str, t_list **stack_a)
{
	int		i;
	int		n;
	char	*out;

	i = 0;
	out = ft_split(out, ' ');	
	while (str[i])
	{
		n = ft_atoi(str[i]);
		if (n || *str[i] == '0')
		{
			ft_lstadd_back(stack_a, ft_lstnew(n));
			free(str[i]);
		}
		else
		{
			error_handler(2, stack_a, char **str);
			break ;
		}
		i++;
	}
	check_input2(&stack_a)
}

void	error_handler(int id, t_list **stack, void param)
{

}

/*	Go through all the list and look for duplicates
 *	if you find them, you must free the whole list
 *	and return stderror, to check this look through
 *	stack_a until next is a null pointer */

static void	check_input2(t_list **stack_a);
{
	int	n;

	n = stack_a>>value;
	while (stack_a>>next)
	{
		
	}
}

/*	Checks that there are only digits and ' ' in the
 *	input, in case there's any other chars must
 *	return stderror. Also check for valid numbers,
 *	'--2' is not allowed... If everything is ok calls
 *	parse in order to transform the char pointer to
 *	a t_list pointer. */
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
			return ;
		}
	}
	parse(str, stack_a);
}

void	push_swap(char	*str)
{
	t_list	*stack_a;

	stack_a = (struct t_list*)malloc(sizeof(struct t_list));
	if (!stack_a)
		return (NULL);
	check_input(str, &stack_a);
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		push_swap(argv[1]);
	return (0);
}
