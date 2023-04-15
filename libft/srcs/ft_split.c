/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:19:01 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/14 10:52:55 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**save_string(const char *s, char c, size_t n, int j)
{
	int		i;
	char	**out;

	out = malloc(sizeof(char *) * (n + 1));
	if (!out)
		return (NULL);
	while (n--)
	{
		i = 0;
		while (s[i] == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		out[j] = malloc(sizeof(char) * (i + 1));
		ft_strlcpy(out[j++], s, i + 1);
		s += i;
	}
	out[j] = NULL;
	return (out);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	n;

	if (!s)
		return (NULL);
	i = 0;
	n = 0;
	while (s[i++])
	{
		if ((s[i] == c && s[i - 1] != c) || (s[i] == '\0' && s[i - 1] != c))
			n++;
	}
	return (save_string(s, c, n, 0));
}
