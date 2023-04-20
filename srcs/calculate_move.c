/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 13:34:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_calculation(c_action solution)
{
	int		i;
	char	**moves;

	i = 0;
	free(solution->actions);
	free(solution);
	return ;
}

static void	save_action(char **actions, char *action, int amount)
{
	if (!actions)
		actions = malloc(sizeof(char **));
}

c_action	calculate_rotate(m_stack *stk, int *value)
{
	c_action	*out;
	int			pos;
	int			*tmp;
	char		*action;

	pos = 0;
	tmp = stk->stack_b->content;
	while (*value != *max_b && stk->stack_b->next) // Calculate pos of 
	{
		stk->stack_b = stk->stack_b->next;
		value = stk->stack_b->content;
		pos++;
	} // Then check if it's cheaper to rotate or reverse_rotate
	out = malloc(sizeof(c_action));
	action = malloc(sizeof(char) * 5);
	if (pos < ft_lstsize(stk->stack_b)) // rotate_b
	{
		action = "rb\n\0";
	}
	else // reverse_rotate_b
	{
		action = "rrb\n\0";
	}
}

c_action	*calculate_move(m_stack *stk, int *max_b, int *min_b)
{
	c_action	*cheapest;
	c_action	*tmp;
	t_list		*lst;
	
	cheapest = malloc(sizeof(c_action));
	lst = stk->stack_a;
	while (lst->next)
	{
		i = lst->content;
		if (*i > *max_b || *i < *min_b) // I have to push_b
		{
			tmp = calculate_rotate(stk, max_b); // Add rotations to actions

			if (*i > *max_b)
				max_b = i;
			else
				min_b = i;
		}
		else
		{
			// Rotate b until I can push lst between [> lst >]
		}
		if (cheapest->amount > tmp->amount)
		{
			free(cheapest);
			cheapest = tmp;
		}
		lst = lst->next;
	}
	return (cheapest);
}
