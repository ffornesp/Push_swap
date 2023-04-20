/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:32:17 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 19:53:45 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpos(t_list *lst, int *value)
{
	int	i;
	int	*tmp;

	i = 1;
	tmp = lst->content;
	while (lst->next)
	{
		if (*tmp == *value)
			return (i);
		lst = lst->next;
		tmp = lst->content;
		i++;
	}
	return (i);
}
