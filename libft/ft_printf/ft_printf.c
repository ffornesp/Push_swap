/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:18:22 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:44:12 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	convert(char *str, va_list args, int count)
{
	if (*(str - 1) == '%')
	{
		if (*str == 'c')
			count = print_c(args, count);
		else if (*str == 's')
			count = print_s(args, count);
		else if (*str == 'p')
			count = print_p(args, count);
		else if (*str == 'd' || *str == 'i')
			count = print_d(args, count);
		else if (*str == 'u')
			count = print_u(args, count);
		else if (*str == 'x' || *str == 'X')
			count = print_x(args, count, *str);
		else if (*str == '%')
		{
			ft_putchar_fd('%', 1);
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start (args, str);
	count = 0;
	while (*str)
	{
		while (*str != '%' && *str)
		{
			ft_putchar_fd((char)*str, 1);
			count++;
			str++;
		}
		if (!*str)
			break ;
		str++;
		count = convert((char *)str, args, count);
		str++;
	}
	va_end(args);
	return (count);
}
