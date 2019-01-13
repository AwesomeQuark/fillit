# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: conoel <conoel@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/10 21:14:13 by conoel            #+#    #+#              #
#    Updated: 2019/01/13 01:33:12 by conoel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

HEADER = include/fillit.h

SRC_NAME = ft_free.c ft_memdup.c ft_memset.c ft_putstr.c ft_strlen.c get_size.c\
is_valid.c load_data.c main.c print_data.c

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJDIR = ./obj/

SRCDIR = ./src/

SRC = ${addprefix $(SRCDIR), $(SRC_NAME)}

OBJ = ${addprefix $(OBJDIR), $(OBJ_NAME)}


all: $(NAME)

$(NAME): obj $(OBJ) ./obj/ft_fillit.o
	@clang $(OBJ) ./obj/ft_fillit.o -o $(NAME)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |    \033[34m\033[1m$(NAME) binary created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"

obj:
	@mkdir -p $(OBJDIR)
	@echo "\n>========= * \033[35m\033[1mCreating obj dir\033[0m * =========<\n"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@clang -c $< -o $@ 
	@echo "\033[35mCompilating : $@\033[0m";

re: fclean all

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@echo "               ~ --- ~\n*< \033[36mEverything has been removed.\033[0m >*\n               ~ --- ~"

# |=============================|
# |======== VISUAL MODE  =======|
# |=============================|

visual : obj $(OBJ) ./obj/ft_fillit_visual.o
	@clang $(OBJ) ./obj/ft_fillit_visual.o -o $(NAME)
	@echo "\n    /-------========= ~~ * ~~ =========-------\ \n-* |    \033[34m\033[1m$(NAME) VISUAL created successfully !\033[0m   | *-\n    \-------========= ~~ * ~~ =========-------/\n"
