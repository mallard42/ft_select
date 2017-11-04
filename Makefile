# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mallard <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/21 17:28:15 by mallard           #+#    #+#              #
#    Updated: 2017/11/03 15:53:11 by mallard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PURPLE = \033[38;5;129m
GREEN = \033[38;5;82m
RED = \033[38;5;208m
DEFAULT = \x1b[0m

NAME = ft_select

LIBFT = ./libft/libft.a

SRC = main.c print.c size.c touch.c arg.c touch2.c signal.c

SRCS = $(addprefix src/, $(SRC));

OBJ = $(SRC:.c=.o)

FLAGS = -Werror -Wextra -Wall -ltermcap

all :  $(NAME)

norme :
	@echo "$(RED)norme sources et includes$(DEFAULT)"
	@norminette ./include libft/include
	@norminette $(SRCS)
	@norminette libft/src

$(LIBFT) :
	@$(MAKE) -C ./libft

$(NAME) : $(LIBFT)
	@echo "$(PURPLE)build $(NAME)$(DEFAULT)"
	@gcc -c $(SRCS)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT)

clean :
	@$(MAKE) clean -C ./libft
	@rm -f $(OBJ)
	@echo "$(GREEN)clean $(NAME)'s object$(DEFAULT)"

fclean : clean
	@echo "$(GREEN)clean $(NAME)$(DEFAULT)"
	@echo "$(GREEN)clean libft.a $(DEFAULT)"
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re : fclean all

.PHONY : re all norme clean fclean
