# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffornes- <ffornes-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:51:17 by ffornes-          #+#    #+#              #
#    Updated: 2023/04/13 16:24:30 by ffornes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR = libftprintf/
LIBFT_FILE = libft.a
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

FT_PRINTF_DIR = libftprintf/ft_printf
FT_PRINTF_FILE = libftprintf.a
LIBFTPRINTF = $(addprefix $(LIBFT_DIR), $(FT_PRINTF_FILE))

all:
		@$(MAKE) -C $(LIBFT_DIR)
		@$(MAKE) -C $(FT_PRINTF_DIR)
		@cp $(LIBFT) ./libft.a
		@cp $(LIBFTPRINTF) ./libftprintf.a
		@echo Compiled Libft and Ft_printf
		@echo Relocated *.a files because

clean:
		@$(MAKE) clean -C $(LIBFT_DIR)
		@echo Removed all Libft object and dependency files
		@$(MAKE) clean -C $(FT_PRINTF_DIR)
		@echo Removed all Ft_printf object and dependency files

fclean:	clean
		@$(MAKE) fclean -C $(LIBFT_DIR)
		@echo Removed libft.a
		@rm $(LIBFT_FILE)
		@echo Removed libft.a copy	
		@$(MAKE) fclean -C $(FT_PRINTF_DIR)
		@echo Removed libftprintf.a
		@rm $(FT_PRINTF_FILE)
		@echo Removed libftprintf.a copy

re:		fclean all

.PHONY: all clean fclean re
