/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:21:05 by ffornes-          #+#    #+#             */
/*   Updated: 2023/04/28 10:49:38 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFFER_SIZE 1000

char	*get_next_line(int fd);
char	*read_to_buff(int fd, char *buffer, char *line);
char	*get_line(char *str);
char	*save_remains(char *str);

#endif
