/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:14:50 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:45:03 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_s(va_list args, int count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	count += ft_strlen(str);
	while (*str)
		ft_putchar_fd(*(str++), 1);
	return (count);
}
