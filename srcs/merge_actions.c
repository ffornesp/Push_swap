/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:54:46 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/25 11:42:37 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	remove_action(t_list **lst)
{
	t_list	*tmp;
	t_list	*aux;
	int		*n;

	aux = *lst;
	n = aux->next->content;
	if (n && (*n == 'C' || *n == 'D'))
	{
		tmp = aux->next;
		aux->next = aux->next->next;
		ft_lstdelone(tmp, (void *)ft_delete);
	}
}

static void	merge_rotation(t_list **lst, int amount)
{
	t_list	*aux;
	int		i;
	int		*n;

	aux = *lst;
	i = amount;
	while (aux)
	{
		n = aux->content;
		if (n && *n == 'H' && amount--)
			*n = 'K';
		else if (n && *n == 'G' && amount--)
			*n = 'J';
		if (i)
		{
			remove_action(&aux);
			i--;
		}
		else
			aux = aux->next;
	}
}

void	check_merge_rotation(t_list **lst)
{
	t_list	*aux;
	int		*c;
	int		*f;
	int		i;
	int		j;

	aux = *lst;
	i = 0;
	j = 0;
	f = aux->content;
	while (aux)
	{
		c = aux->content;
		if (c && (*c == 'G' || *c == 'H'))
			i++;
		if (c && f && (((*c == 'C') && (*f == 'G')) 
					|| ((*c == 'D') && (*f == 'H'))))
			j++;
		aux = aux->next;
	}
	if (j < i)
		i = j;
	if (i > 1)
		merge_rotation(lst, i);
}
