/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:00:08 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 09:50:39 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actions_init(t_actions **actions)
{
	t_actions	*tmp;

	tmp = *actions;
	tmp->c = malloc(sizeof(int));
	*tmp->c = 0;
	tmp->g = malloc(sizeof(int));
	*tmp->g = 0;
	tmp->d = malloc(sizeof(int));
	*tmp->d = 0;
	tmp->h = malloc(sizeof(int));
	*tmp->h = 0;
	tmp->j = malloc(sizeof(int));
	*tmp->j = 0;
	tmp->k = malloc(sizeof(int));
	*tmp->k = 0;
}
