/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:42:41 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:45:15 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u(va_list args, int count)
{
	unsigned long	i;
	int				j;
	char			str[20];

	i = (unsigned long)va_arg(args, unsigned int);
	j = 0;
	if (i == 0)
		str[j++] = '0';
	while (i > 0)
	{
		str[j++] = (i % 10) + '0';
		if (i < 10)
			break ;
		else
			i /= 10;
	}
	count += j;
	while (j--)
		ft_putchar_fd(str[j], 1);
	return (count);
}
