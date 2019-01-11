# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/01/11 13:31:45 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADER = include/fillit.h

SRC_NAME = main.c load_data.c ft_memdup.c ft_strlen.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJDIR = ./obj/

SRCDIR = ./src/

SRC = ${addprefix $(SRCDIR), $(SRC_NAME)}

OBJ = ${addprefix $(OBJDIR), $(OBJ_NAME)}


all: $(NAME)

$(NAME): obj $(OBJ)
	@clang $(OBJ) -o $(NAME)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |   \033[34m\033[1m$(NAME) binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

obj:
	@mkdir -p obj
	@echo "\n>========= * \033[35m\033[1mCreating obj dir\033[0m * =========<\n"

./obj/%.o: ./src/%.c
	@clang -Wall -Werror -Wextra -c $< -o $@ 
	@echo "\033[35mCompilating : $@\033[0m";

re: fclean all

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(NAME)
	@rm -Rf $(OBJDIR)
	@echo "               ~ --- ~\n*< \033[36mEverything has been removed.\033[0m >*\n               ~ --- ~"
