# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:51:17 by ffornes-          #+#    #+#              #
#    Updated: 2023/04/14 14:37:20 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HDR_DIR = include/
HDR_FILES = libft.h printf.h
HDRS = $(addprefix $(HDR_DIR), $(HDR_FILES))

SRCS_LIBFT = $(addprefix srcs/, ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
			ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
			ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c ) 
SRCS_PRINTF = $(addprefix ft_printf/srcs/, print_c.c print_d.c print_p.c print_s.c print_u.c print_x.c ft_printf.c)

OBJ_DIR = ./obj/

OBJS_LIBFT = $(SRCS_LIBFT:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJS_LIBFT) $(OBJS_PRINTF))

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: 		$(NAME)

$(NAME):	$(OBJS)
			ar rc $@ $(OBJS)

$(OBJ_DIR):
			@mkdir $@

.c.o:		$(CC) $(CFLAGS) -I $(HDRS) -c $@ -o $<

clean: 		
			@$(RM) $(OBJS)

fclean: 	clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
