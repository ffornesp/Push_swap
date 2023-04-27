/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:24:47 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 12:10:18 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

# define SWAP_A 'A'
# define PUSH_A 'B'
# define ROTATE_A 'C'
# define REV_ROTATE_A 'D'
# define SWAP_B 'E'
# define PUSH_B 'F'
# define ROTATE_B 'G'
# define REV_ROTATE_B 'H'
# define SWAP_S 'I'
# define ROTATE_R 'J'
# define REV_ROTATE_R 'K'

typedef struct lst_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

typedef struct lst_actions
{
	int	*ra;
	int	*rb;
	int	*rra;
	int	*rrb;
	int	*rr;
	int	*rrr;
}	t_actions;

void	push_swap(char **str);

t_list	*parse(char **str);
int		check_digits(char *str);
int		check_duplicates(t_list *stack);
int		ft_atol(const char *str);
char	*check_zeros(char *input);

void	swap_a(t_stack *stk, int print);
void	swap_b(t_stack *stk, int print);
void	swap_s(t_stack *stk, int print);

void	push_a(t_stack *stk, int print);
void	push_b(t_stack *stk, int print);

void	rotate_a(t_stack *stk, int print);
void	rotate_b(t_stack *stk, int print);
void	rotate_r(t_stack *stk, int print);

void	reverse_rotate_a(t_stack *stk, int print);
void	reverse_rotate_b(t_stack *stk, int print);
void	reverse_rotate_r(t_stack *stk, int print);

void	sort_3(t_stack *stk);
void	init_sort(t_stack *stk);
int		*stk_limits(t_list *lst);
t_list	*calculate_moves(t_stack *stk, int *limits, int id);
void	*calc_rot(t_list *lst, int *value, int stack, t_list **action);
void	check_merge_rotation(t_list **lst);

void	actions_init(t_actions **actions);
void	actions_clear(t_actions **actions);

void	add_push(t_list **action, int stack);

void	parse_move(t_stack *stk, t_list *actions);
int		finish_check(t_stack *stk);
#endif
