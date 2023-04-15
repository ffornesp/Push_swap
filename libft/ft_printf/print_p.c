/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:42:50 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:44:54 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_p(va_list args, int count)
{
	unsigned long	ptr;
	char			out[20];
	int				i;

	ptr = (unsigned long)va_arg(args, char *);
	i = 0;
	if (!ptr || ptr == 0)
		out[i++] = '0';
	while (ptr > 0)
	{
		if (ptr % 16 >= 10)
			out[i++] = ((ptr % 16) - 10 + 'a');
		else
			out[i++] = ((ptr % 16) + '0');
		ptr /= 16;
	}
	out[i++] = 'x';
	out[i++] = '0';
	count += i;
	while (i-- > 0)
		ft_putchar_fd(out[i], 1);
	return (count);
}
