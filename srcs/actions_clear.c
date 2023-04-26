/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:01:03 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 11:30:06 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	actions_clear(t_actions **actions)
{
	t_actions	*aux;

	aux = *actions;
	free(aux->c);
	free(aux->g);
	free(aux->d);
	free(aux->h);
	free(aux->j);
	free(aux->k);
	free(aux);
}
