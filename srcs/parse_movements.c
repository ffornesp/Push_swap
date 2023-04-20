/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:06:14 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 12:24:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_s(m_stack *stk, char *movement)
{
	int	i;

	i = 0;
	movement++;
	if (*movement == 'a')
		swap_a(stk);
	else if (*movement == 'b')
		swap_b(stk);
	else
		swap_s(stk);
}

static void	parse_p(m_stack *stk, char *movement)
{
	int	i;

	i = 0;
	movement++;
	if (*movement == 'a')
		push_a(stk);
	else
		push_b(stk);
}

static void	parse_r(m_stack *stk, char *movement)
{
	int	i;

	i = 0;
	movement++;
	if (*movement == 'a')
		rotate_a(stk);
	else if (*movement == 'b')
		rotate_b(stk);
	else if (*movement == 'r' && !*(movement + 1))
		rotate_r(stk);
	else if (*(movement + 1) == 'a')
		reverse_rotate_a(stk);
	else if (*(movement + 1) == 'b')
		reverse_rotate_b(stk);
	else
		reverse_rotate_r(stk);
}

void	parse_move(m_stack *stk, c_action solution)
{
	char	**moves;
	int		i;

	i = 0;
	moves = solution->actions;
	while (moves[i])
	{
		if (*moves[i] == 's')
			parse_s(stk, moves[i]);
		else if (*moves[i] == 'r')
			parse_r(stk, moves[i]);
		else if (*moves[i] == 'p')
			parse_p(stk, moves[i]);
		ft_printf("%s\n", moves[i]);
		free(moves[i]);
		i++;
	}
	free(moves);
	return ;
}
