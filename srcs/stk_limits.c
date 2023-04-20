/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:12:59 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 19:41:10 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_limits(t_list *lst, int *max, int *min)
{
	t_list	*aux;
	int		*i;

	aux = lst;
	while (aux)
	{
		i = aux->content;
		if (*i > *max)
			*max = *i;
		else if (*i < *min)
			*min = *i;
		aux = aux->next;
	}
	return ;
}
