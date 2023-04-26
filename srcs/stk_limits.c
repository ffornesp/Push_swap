/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:12:59 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 17:06:52 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stk_limits(t_list *lst)
{
	t_list	*aux;
	int		*limits;

	limits = malloc(sizeof(int) * 2);
	aux = lst;
	limits[0] = *(int *)aux->content;
	limits[1] = *(int *)aux->content;
	while (aux)
	{
		if (*(int *)aux->content > limits[1])
			limits[1] = *(int *)aux->content;
		else if (*(int *)aux->content < limits[0])
			limits[0] = *(int *)aux->content;
		aux = aux->next;
	}
	return (limits);
}
