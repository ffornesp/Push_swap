/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 09:53:23 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/13 17:19:41 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	parse_input(char *str)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	j = 0;
	while (*(str + i))
	{
		if (j != 0)
		{
			i -= j;
			*out = malloc(sizeof(char *) * (j + 1));
			if (!out)
				return (NULL);
			while (j > 0)
			{
				*out = *(str + i);
				i++;
			}
		}
		while (*(str + i) < '0' || *(str + i) > '9')
			i++;
		while (*(str + i) >= '0' && *(str + i) <= '9')
			j++;
	}
}
