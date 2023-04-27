/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:01:28 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 13:17:31 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	finish_check(t_stack *stk)
{
	int		*max;
	int		*min;
	int		*n;
	t_list	*lst;

	lst = stk->stack_a;
	max = lst->content;
	min = lst->content;
	while (lst->next)
	{
		n = lst->next->content;
		if (*n > *max && *n > *min)
		{
			max = lst->next->content;
			lst = lst->next;
		}
		else
			return (0);
	}
	return (1);
}

static void	rotate_finish(t_stack *stk)
{
	int		*limits;
	int		size;
	t_list	*aux;

	limits = NULL;
	aux = stk->stack_a;
	limits = stk_limits(aux);
	size = ft_lstsize(stk->stack_a) / 2;
	while (finish_check(stk) < 1)
	{
		if (ft_lstpos(stk->stack_a, &limits[0]) < size)
			rotate_a(stk, 1);
		else if (ft_lstpos(stk->stack_a, &limits[0]) >= size)
			reverse_rotate_a(stk, 1);
	}
	free(limits);
}

static void	start_move(t_stack *stk)
{
	t_list	*actions;
	int		*limits;

	while (ft_lstsize(stk->stack_a) > 3)
	{
		limits = stk_limits(stk->stack_b);
		actions = calculate_moves(stk, limits, 0);
		parse_move(stk, actions);
		free(limits);
		ft_lstclear(&actions, (void *) ft_delete);
	}
	sort_3(stk);
	while (ft_lstsize(stk->stack_b) > 0)
	{
		limits = stk_limits(stk->stack_a);
		actions = calculate_moves(stk, limits, 1);
		parse_move(stk, actions);
		free(limits);
		ft_lstclear(&actions, (void *)ft_delete);
	}
	rotate_finish(stk);
}

void	sort_3(t_stack *stk)
{
	int		*i;
	int		*j;
	int		*k;

	while (finish_check(stk) < 1)
	{
		if (ft_lstsize(stk->stack_a) < 3)
			swap_a(stk, 1);
		else
		{
			i = stk->stack_a->content;
			j = stk->stack_a->next->content;
			k = stk->stack_a->next->next->content;
			if (*j > *i && *j > *k)
				reverse_rotate_a(stk, 1);
			else if (*i > *j && *i > *k)
				rotate_a(stk, 1);
			else if (*i > *j && *i < *k)
				swap_a(stk, 1);
		}
	}
}

void	init_sort(t_stack *stk)
{
	int	*limits;

	if (finish_check(stk) < 1)
	{
		push_b(stk, 1);
		if (ft_lstsize(stk->stack_a) > 3)
		{
			push_b(stk, 1);
			limits = stk_limits(stk->stack_b);
			start_move(stk);
			free(limits);
		}
		else if (ft_lstsize(stk->stack_a) > 0)
		{
			start_move(stk);
			rotate_finish(stk);
		}
	}
}
