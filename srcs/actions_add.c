/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 17:18:46 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 17:19:20 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_actions(t_list **lst, int action, int times)
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
