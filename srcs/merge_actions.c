/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:54:46 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 11:36:49 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_actions(t_list **lst, int action, int times)
{
	t_list	*aux;
	int		*tmp;

	aux = *lst;
	while (times)
	{
		tmp = malloc(sizeof(int));
		*tmp = action;
		if (!aux->content)
			aux->content = tmp;
		else
			ft_lstadd_back(lst, ft_lstnew(tmp));
		times--;
	}
}

static t_list	*merge_actions(t_actions **acts)
{
	t_list		*lst;
	t_actions	*actions;

	actions = *acts;
	lst = ft_lstnew(NULL);
	if (*actions->c > 0)
		add_actions(&lst, 'C', *actions->c);
	if (*actions->g > 0)
		add_actions(&lst, 'G', *actions->g);
	if (*actions->d > 0)
		add_actions(&lst, 'D', *actions->d);
	if (*actions->h > 0)
		add_actions(&lst, 'H', *actions->h);
	if (*actions->j > 0)
		add_actions(&lst, 'J', *actions->j);
	if (*actions->k > 0)
		add_actions(&lst, 'K', *actions->k);
	return (lst);
}

static void	check_merge_2(t_list **lst, t_actions **acts)
{
	t_list		*aux;
	t_actions	*actions;

	aux = *lst;
	actions = *acts;
	while (*actions->c > 0 && *actions->g > 0)
	{
		*actions->j += 1;
		*actions->c -= 1;
		*actions->g -= 1;
	}
	while (*actions->d > 0 && *actions->h > 0)
	{
		*actions->k += 1;
		*actions->d -= 1;
		*actions->h -= 1;
	}
	if (*actions->j > 0 || *actions->k > 0)
	{
		*lst = merge_actions(acts);
		ft_lstclear(&aux, (void *)ft_delete);
	}
}

void	check_merge_rotation(t_list **lst)
{
	int			*tmp;
	t_list		*aux;
	t_actions	*actions;

	aux = *lst;
	actions = malloc(sizeof(t_actions));
	actions_initialize(&actions);
	while (aux)
	{
		tmp = aux->content;
		if (tmp && actions)
		{
			if (*tmp == 'C')
				*actions->c += 1;
			else if (*tmp == 'G')
				*actions->g += 1;
			else if (*tmp == 'D')
				*actions->d += 1;
			else if (*tmp == 'H')
				*actions->h += 1;
		}
		aux = aux->next;
	}
	check_merge_2(lst, &actions);
	actions_clear(&actions);
}
