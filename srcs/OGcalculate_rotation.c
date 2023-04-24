/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:29:59 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/20 18:56:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Adds whatever rotations are left that couldn't be merged in rr || rrr //
static void	merge_rot_2(int times, char *str, c_action *actions, char *out)
{
	char	*aux;
	int		n_actions;
	int		i;

	aux = out;
	n_actions = 0;
	while (times)
	{
		out = ft_strjoin(out, str);
		free(aux);
		times--;
	}
	free(actions->moves);
	actions->moves = out;
	i = 0;
	while (actions->moves[i])
	{
		if (actions->moves[i++] == '\n')
			n_actions++;
	}
	*actions->amount = n_actions;
}

// Merges ra && rb into rr || rra && rrb into rrr //
static void	merge_rot(c_action *actions, int a_rot, int b_rot)
{
	char	*out;
	char	*aux;
	char	*str;

	str = "rr\n";
	if (actions->moves[1] == 'r')
		str = "rrr\n";
	out = ft_strdup("");
	while (a_rot && b_rot)
	{
		aux = out;
		out = ft_strjoin(out, str);
		free(aux);
		a_rot--;
		b_rot--;
	}
	if (a_rot && str[1] == 'r' && str[2] == '\n')
		merge_rot_2(a_rot, "ra\n", actions, out);
	else if (a_rot && str[2] == '3')
		merge_rot_2(a_rot, "rra\n", actions, out);
	else if (b_rot && str[1] == 'r' && str[2] == '\n')
		merge_rot_2(b_rot, "rb\n", actions, out);
	else if (b_rot && str[2] == 'r')
		merge_rot_2(b_rot, "rrb\n", actions, out);
}

void	merge_rot_check(c_action *actions)
{
	int		i;
	int		a_rot;
	int		b_rot;
	char	*str;
	char	**tmp;

	i = 0;
	a_rot = 0;
	b_rot = 0;
	tmp = ft_split(actions->moves, '\n');
	str = "rra";
	if (tmp[0][1] == 'b')
		str = "ra";
	while (tmp[i])
	{
		if (tmp[i][1] == 'b' || tmp[i][2] == 'b')
			b_rot++;
		if (tmp[i] == str)
			a_rot++;
		free(tmp[i++]);
	}
	if (a_rot > 0)
		merge_rot(actions, a_rot, b_rot);
	free(tmp);
}

c_action	*calculate_rotation(t_list *lst, int *value, int stack, int *moves)
{
	char		*tmp;
	c_action	*actions;
	int			*movements;

	tmp = NULL;
	if (moves)
		movements = moves;
	else
	{
		movements = malloc(sizeof(int));
		*movements = 0;
	}
	actions = malloc(sizeof(c_action));
	actions->amount = movements;
	actions->moves = ft_strdup("");
	if (ft_lstpos(lst, value) < ft_lstsize(lst))
	{
		*movements += ft_lstpos(lst, value);
		ft_printf(RED"AYAYAYA %d\n"WHITE, ft_lstpos(lst, value));
		tmp = "rb\n\0";
		if (stack < 1)
			tmp = "ra\n\0";
	}
	else
	{
		movements += ft_lstsize(lst) - ft_lstpos(lst, value);
		tmp = "rrb\n\0";
		if (stack < 1)
			tmp = "rra\n\0";
	}
	add_to_moves(actions, *actions->amount, tmp);
	//free(tmp);
	return (actions);
}