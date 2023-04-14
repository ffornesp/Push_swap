# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:21:42 by ffornes-          #+#    #+#              #
#    Updated: 2023/04/14 13:49:22 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

LIBFT_DIR = ../libft/
LIBFT_FILE = libft.a
LIBFT_HDR = $(addprefix $(LIBFT_DIR), include)
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

HDR_DIR =	./include/

SRC_DIR =	src/
SRC_FILES = print_c.c print_d.c print_p.c \
			print_s.c print_u.c print_x.c \
			ft_printf.c 
SRCS = 		$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR =	obj/
OBJ_FILES =	$(SRC_FILES:.c=.o)
OBJS =		$(addprefix $(OBJ_DIR), $(OBJ_FILES))

INCLUDE = -I ./include/ -I ../libft/include/ -I


CC = 		gcc
CFLAGS = 	-Wall -Wextra -Werror -I$(HDR_DIR)
RM =		rm -rf

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
			ar rc $@ $(OBJS) $(LIBFT)

$(LIBFT):	$(LIBFT_DIR)
			make -C $(LIBFT_DIR)

$(OBJ_DIR):
			mkdir $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)
			make -C $(LIBFT_DIR) clean

fclean:		clean
			@$(RM) $(NAME)
			make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:	all clean fclean re
