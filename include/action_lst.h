/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_lst.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:30:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 13:29:23 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_LST_H
# define ACTION_LST_H

typedef struct	lst_actions
{
	int	*ra;
	int	*rb;
	int	*rra;
	int	*rrb;
	int	*rr;
	int	*rrr;
}	t_actions;

void	actions_init(t_actions **actions);
void	actions_clear(t_actions **actions);
#endif
