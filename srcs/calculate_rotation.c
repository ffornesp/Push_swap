/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:29:59 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 16:32:11 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	fill_list(t_list **lst, int amount, int *value)
{
	t_list	*aux;
	int		*n;

	aux = *lst;
	while (amount)
	{
		n = malloc(sizeof(int));
		*n = *value;
		if (!aux->content)
			aux->content = n;
		else
			ft_lstadd_back(lst, ft_lstnew(n));
		ft_printf("Added %c\n", (char) *n);
		amount--;
	}
}

void	*calc_rotation(t_list *lst, int *value, int stack, t_list **action)
{
	int	n;
	int	i;

	i = 0;
	if (ft_lstpos(lst, value) >= 1)
	{
		if (ft_lstpos(lst, value) < ft_lstsize(lst) / 2)
		{
			i = ft_lstpos(lst, value);
			n = 'G';
			if (stack < 1)
				n = 'C';
		}
		else
		{
			i = ft_lstsize(lst) - ft_lstpos(lst, value);
			n = 'H';
			if (stack < 1)
				n = 'D';
		}
		fill_list(action, i, &n);
	}
	return (*action);
}