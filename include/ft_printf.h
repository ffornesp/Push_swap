/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:43:37 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 13:50:44 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		print_c(va_list args, int count);
int		print_s(va_list args, int count);
int		print_p(va_list args, int count);
int		print_d(va_list args, int count);
int		print_u(va_list args, int count);
int		print_x(va_list args, int count, char c);

#endif
