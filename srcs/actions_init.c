/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:00:08 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 11:56:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
