/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:39:26 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:45:25 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_x(va_list args, int count, char x)
{
	unsigned int		i;
	int					j;
	char				str[9];
	char				c;

	i = (unsigned int)va_arg(args, int);
	j = 0;
	c = 'a';
	if (x < 'a')
		c = 'A';
	if (i == 0)
		str[j] = '0';
	while (i != 0)
	{
		str[j] = ((char)(i % 16)) + c - 10;
		if ((i % 16) < 10)
			str[j] = ((char)(i % 16)) + '0';
		i /= 16;
		if (i != 0)
			j++;
	}
	count += j + 1;
	while (j >= 0)
		ft_putchar_fd(str[j--], 1);
	return (count);
}
