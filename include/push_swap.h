/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:24:47 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/27 13:09:53 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct lst_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_stack;

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
void	check_merge(t_list **lst);

void	add_push(t_list **action, int stack);

void	parse_move(t_stack *stk, t_list *actions);
#endif
