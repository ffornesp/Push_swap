/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:01:03 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 11:56:01 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actions_clear(t_actions **actions)
{
	t_actions	*aux;

	aux = *actions;
	free(aux->ra);
	free(aux->rb);
	free(aux->rra);
	free(aux->rrb);
	free(aux->rr);
	free(aux->rrr);
	free(aux);
}
