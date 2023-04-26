/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:24:47 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/26 13:10:40 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include "ft_printf.h"
# include <limits.h>

typedef struct lst_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

typedef struct lst_actions
{
	int	*c;
	int	*g;
	int	*d;
	int	*h;
	int	*j;
	int	*k;
}	t_actions;

void	push_swap(char **str);
t_list	*parse(char **str);
int		check_digits(char *str);
int		check_duplicates(t_list *stack);
int		ft_atol(const char *str);
char	*check_zeros(char *input);
int		finish_check(t_stack *stk);
void	swap_a(t_stack *stk, int check);
void	swap_b(t_stack *stk, int check);
void	swap_s(t_stack *stk);
void	push_a(t_stack *stk);
void	push_b(t_stack *stk);
void	rotate_a(t_stack *stk, int check);
void	rotate_b(t_stack *stk, int check);
void	rotate_r(t_stack *stk);
void	reverse_rotate_a(t_stack *stk, int check);
void	reverse_rotate_b(t_stack *stk, int check);
void	reverse_rotate_r(t_stack *stk);
void	sort_3(t_stack *stk);
void	init_sort(t_stack *stk);
t_list	*calculate_moves(t_stack *stk, int *max, int *min);
t_list	*calculate_push_back(t_stack *stk, int *max, int *min);
void	*calc_rot(t_list *lst, int *value, int stack, t_list **action);
void	check_merge_rotation(t_list **lst);
void	actions_initialize(t_actions **actions);
void	actions_clear(t_actions **actions);
void	add_push(t_list **action, int stack);
void	parse_move(t_stack *stk, t_list *actions);
void	stk_limits(t_list *lst, int *max, int *min);
#endif
