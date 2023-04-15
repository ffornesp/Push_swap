/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:16:58 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:44:42 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_d(va_list args, int count)
{
	long int	i;

	i = (long int)va_arg(args, int);
	ft_putnbr_fd(i, 1);
	if (i <= 0)
		count++;
	if (i < 0)
		i *= -1;
	while (i != 0)
	{
		if (i < 10)
			i = 0;
		i /= 10;
		count++;
	}
	return (count);
}
