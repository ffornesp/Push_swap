# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:51:17 by ffornes-          #+#    #+#              #
#    Updated: 2023/05/01 11:14:20 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

LIBFT_DIR = libft/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

###############################################################################
#									SRCS									  #
###############################################################################

SRCS_DIR = srcs/
SRC_FILES =	 push_swap.c \
			 parse_input.c parse_movements.c \
			 check_input.c \
			 sort.c \
			 calculate_move.c calculate_rotation.c \
			 merge_actions.c m_actions_lst.c \
			 stk_limits.c

SRCS_ACTIONS_DIR = actions/
SRC_ACTION_FILES = swap.c push.c rotate.c reverse_rotate.c

SRC_BONUS_PS_FILES = 	 parse_input.c parse_movements.c \
						 check_input.c \
						 sort.c \
						 calculate_move.c calculate_rotation.c \
						 merge_actions.c m_actions_lst.c \
						 stk_limits.c
SRCS_BONUS_DIR = bonus/
SRC_BONUS_FILES = checker.c

###############################################################################
#									OBJS									  #
###############################################################################

OBJS_DIR =	objs/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_DIR), $(OBJ_FILES))

OBJS_ACTIONS_DIR = objs/actions/
OBJ_ACTION_FILES = $(SRC_ACTION_FILES:.c=.o)
OBJS_ACTIONS = $(addprefix $(OBJS_ACTIONS_DIR), $(OBJ_ACTION_FILES))

OBJ_BONUS_PS_FILES = $(SRC_BONUS_PS_FILES:.c=.o)
OBJS_BONUS_PS = $(addprefix $(OBJS_DIR), $(OBJ_BONUS_PS_FILES))

OBJS_BONUS_DIR = objs_bonus/
OBJ_BONUS_FILES = $(SRC_BONUS_FILES:.c=.o)
OBJS_BONUS = $(addprefix $(OBJS_BONUS_DIR), $(OBJ_BONUS_FILES))

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
bonus:		$(NAME_BONUS)

m_libft:
			@make -C $(LIBFT_DIR)

$(NAME):	m_libft $(OBJS_DIR) $(OBJS) $(OBJS_ACTIONS_DIR) $(OBJS_ACTIONS)
			@$(CC) $(INCLUDE) $(OBJS) $(OBJS_ACTIONS) -Llibft/ -lft -o $@
$(NAME_BONUS):	m_libft $(OBJS_DIR) $(OBJS_BONUS_PS) $(OBJS_ACTIONS_DIR) $(OBJS_ACTIONS) $(OBJS_BONUS_DIR) $(OBJS_BONUS)
				@$(CC) $(INCLUDE) $(OBJS_BONUS_PS) $(OBJS_ACTIONS) $(OBJS_BONUS) $(LIBFT) -o $@

$(OBJS_DIR):
						@mkdir $@
$(OBJS_ACTIONS_DIR):
						@mkdir $@
$(OBJS_BONUS_DIR):
						@mkdir $@

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS_ACTIONS_DIR)%.o:	$(SRCS_ACTIONS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(OBJS_BONUS_DIR)%.o: $(SRCS_BONUS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean: 		
			make -C $(LIBFT_DIR) clean
			@$(RM) $(OBJS)
			@$(RM) $(OBJS_ACTIONS)
			@$(RM) $(OBJS_BONUS)

fclean: 	clean
			make -C $(LIBFT_DIR) fclean
			@$(RM) $(NAME)
			@$(RM) $(NAME_BONUS)

re:			fclean all
			

.PHONY: all clean fclean re bonus
