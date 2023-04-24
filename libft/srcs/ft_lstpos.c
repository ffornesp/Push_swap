/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:32:17 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/24 12:42:17 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpos(t_list *lst, int *value)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = lst->content;
	while (lst)
	{
		if (*tmp == *value)
			return (i);
		lst = lst->next;
		tmp = lst->content;
		i++;
	}
	return (i);
}
