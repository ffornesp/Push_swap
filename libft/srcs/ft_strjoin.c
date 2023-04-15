/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:34:20 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:53:44 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size1;
	size_t	size2;
	char	*str;

	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	str = malloc (sizeof(char) * (size1 + size2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size1 + 1);
	ft_strlcat((char *)(str + size1), s2, size2 + 1);
	return (str);
}
