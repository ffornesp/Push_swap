/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:32:17 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 14:39:57 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstpos(t_list *lst, void *value)
{
	int		i;
	void	*tmp;

	i = 0;
	tmp = lst->content;
	while (tmp != value && lst->next)
	{
		lst = lst->next;
		tmp = lst->content;
		i++;
	}
	return (i);
}
