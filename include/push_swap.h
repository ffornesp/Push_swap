/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:24:47 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/17 16:47:21 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"
# include <limits.h>

void	ft_lstfree(t_list **lst);
void	push_swap(char **str);
t_list	**parse(char **str);
int		check_digits(char *str);
int		check_duplicates(t_list **stack);
char	*check_zeros(char *input);

#endif
