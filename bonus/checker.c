/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 10:38:06 by ffornes-          #+#    #+#             */
/*   Updated: 2023/05/01 10:02:19 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	end_ex(t_stack *stk)
{
	ft_lstclear(&stk->stack_a, (void *)ft_delete);
	free(stk);
}

static void	end_check(t_stack *stk)
{
	if (finish_check(stk))
		ft_putstr_fd("OK\n", 1);
	else if (!finish_check(stk))
		ft_putstr_fd("KO\n", 1);
	end_ex(stk);
}

static int	run_actions(char *line, t_stack *stk)
{
	if (!(ft_strncmp(line, "sa\n", 3)))
		swap_a(stk, 0);
	else if (!(ft_strncmp(line, "sb\n", 3)))
		swap_b(stk, 0);
	else if (!(ft_strncmp(line, "ss\n", 3)))
		swap_s(stk, 0);
	else if (!(ft_strncmp(line, "pa\n", 3)))
		push_a(stk, 0);
	else if (!(ft_strncmp(line, "pb\n", 3)))
		push_b(stk, 0);
	else if (!(ft_strncmp(line, "ra\n", 3)))
		rotate_a(stk, 0);
	else if (!(ft_strncmp(line, "rb\n", 3)))
		rotate_b(stk, 0);
	else if (!(ft_strncmp(line, "rr\n", 3)))
		rotate_r(stk, 0);
	else if (!(ft_strncmp(line, "rra\n", 4)))
		reverse_rotate_a(stk, 0);
	else if (!(ft_strncmp(line, "rrb\n", 4)))
		reverse_rotate_b(stk, 0);
	else if (!(ft_strncmp(line, "rrr\n", 4)))
		reverse_rotate_r(stk, 0);
	else
		return (1);
	return (0);
}

static void	checker(t_stack *stk)
{
	char	*line;

	if (stk->stack_a)
	{
		line = get_next_line(0);
		while (line)
		{
			if (run_actions(line, stk))
			{
				ft_putstr_fd("Error\n", 2);
				end_ex(stk);
				free(line);
				return ;
			}
			free(line);
			line = get_next_line(0);
		}
	}
	else
	{
		free(stk);
		return ;
	}
	end_check(stk);
}

int	main(int argc, char *argv[])
{
	t_stack	*stk;

	if (argc < 2)
		return (0);
	if (*argv[1] == '\0')
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	stk = malloc(sizeof(t_stack));
	stk->stack_a = parse(argv);
	checker(stk);
	return (0);
}
