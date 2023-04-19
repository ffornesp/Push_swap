/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:24:47 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/19 10:34:55 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include <limits.h>

#ifndef GREEN
# define GREEN	"\x1B[32m"
#endif
#ifndef YELLOW
# define YELLOW "\x1B[33m"
#endif
#ifndef RED
# define RED	"\x1B[31m"
#endif
#ifndef WHITE
#define WHITE	"\x1B[37m"
#endif

typedef struct	lst_stack
{
	t_list	*stack_a;
	t_list	*stack_b;
}	m_stack;

void	push_swap(char **str);
t_list	*parse(char **str);
int		check_digits(char *str);
int		check_duplicates(t_list *stack);
char	*check_zeros(char *input);

void	swap_a(m_stack *stk);
void	swap_b(m_stack *stk);
void	swap_ss(m_stack *stk);

void	check_contents(t_list *stack);

#endif
