/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_actions_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:00:08 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 13:20:07 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "action_lst.h"
#include <stdlib.h>

void	actions_init(t_actions **actions)
{
	t_actions	*tmp;

	tmp = *actions;
	tmp->ra = malloc(sizeof(int));
	*tmp->ra = 0;
	tmp->rb = malloc(sizeof(int));
	*tmp->rb = 0;
	tmp->rra = malloc(sizeof(int));
	*tmp->rra = 0;
	tmp->rrb = malloc(sizeof(int));
	*tmp->rrb = 0;
	tmp->rr = malloc(sizeof(int));
	*tmp->rr = 0;
	tmp->rrr = malloc(sizeof(int));
	*tmp->rrr = 0;
}

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
