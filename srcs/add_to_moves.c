/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_to_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:42:09 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 20:08:51 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Must free char *act if was allocated, in function calling this function.
void	add_to_moves(c_action *actions, int times, char *act)
{
	char	*aux;
	int		i;

	i = *actions->amount;
	aux = actions->moves;
	while (times)
	{
		actions->moves = ft_strjoin(actions->moves, act);
		free(aux);
		aux = actions->moves;
		times--;
	}
	// Saves OK action amount and action moves
}
