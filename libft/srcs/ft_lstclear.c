/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:12:30 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/28 12:46:00 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	aux = *lst;
	while (aux)
	{
		*lst = aux->next;
		(*del)(aux->content);
		free(aux);
		aux = *lst;
	}
	*lst = NULL;
}
