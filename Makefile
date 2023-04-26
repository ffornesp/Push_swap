# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:51:17 by ffornes-          #+#    #+#              #
#    Updated: 2023/04/26 11:27:28 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

###############################################################################
#									SRCS									  #
###############################################################################

SRCS_DIR = srcs/
SRC_FILES =	 push_swap.c \
			 parse_input.c parse_movements.c \
			 check_input.c check_sort.c \
			 sort_3.c sort_any.c \
			 calculate_move.c calculate_rotation.c \
			 merge_actions.c actions_initialize.c actions_clear.c \
			 stk_limits.c
SRCS = 	$(addprefix $(SRCS_DIR), $(SRC_FILES))

SRCS_ACTIONS_DIR = actions/
SRC_ACTION_FILES = swap.c push.c rotate.c reverse_rotate.c
SRCS_ACTIONS = $(addprefix $(SRCS_ACTIONS_DIR), $(SRC_ACTION_FILES))

###############################################################################
#									OBJS									  #
###############################################################################

OBJS_DIR =	objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

OBJS_ACTIONS_DIR = objs/actions/
OBJ_ACTION_FILES = $(SRC_ACTION_FILES:.c=.o)
OBJS_ACTIONS = $(addprefix $(OBJS_ACTIONS_DIR), $(OBJ_ACTION_FILES))

###############################################################################
#									OTHER									  #
###############################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar rc
INCLUDE  = -I ./include/ -I ./libft/include/

###############################################################################
#									RULES									  #
###############################################################################

all: 		$(NAME)

$(LIBFT_DIR)$(LIBFT_FILE):	$(LIBFT_DIR)
			make -C $(LIBFT_DIR)

$(NAME):	$(LIBFT_DIR)$(LIBFT_FILE) $(OBJS_DIR) $(OBJS) $(OBJS_ACTIONS_DIR) $(OBJS_ACTIONS)
			$(CC) $(INCLUDE) $(OBJS) $(OBJS_ACTIONS) -lft -Llibft/ -o $@

$(OBJS_DIR):
						@mkdir $@
$(OBJS_ACTIONS_DIR):
						@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS_ACTIONS_DIR)%.o:	$(SRCS_ACTIONS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
clean: 		
			make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS)

fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
