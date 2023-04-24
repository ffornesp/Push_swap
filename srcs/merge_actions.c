/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:54:46 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 17:14:26 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_rotation(t_list **lst, int amount)
{
	t_list	*aux;
	t_list	*tmp;
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
			n = aux->next->content;
			if (n && (*n == 'C' || *n == 'D'))
			{
				tmp = aux->next;
				aux = tmp->next;
				ft_lstdelone(tmp, (void *) ft_delete);
				i--;
			}
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
		if ((*c == 'G' || *c == 'H'))
			i++;
		if (((*c == 'C') && (*f == 'G')) || ((*c == 'D') && (*f == 'H')))
			j++;
		aux = aux->next;
	}
	if (j < i)
		i = j;
	merge_rotation(lst, i);
}
