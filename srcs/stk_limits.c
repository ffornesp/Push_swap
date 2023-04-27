/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:12:59 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 13:31:58 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
