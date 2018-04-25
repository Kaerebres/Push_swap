# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csimon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/04 11:17:54 by csimon            #+#    #+#              #
#    Updated: 2017/10/13 17:32:00 by csimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
NAME2 = push_swap
FLAG = -Wall -Wextra -Werror
OBJ = $(SRCC:.c=.o)
OBJ2 = $(SRCP:.c=.o)

SRC = checker.c moves_1.c moves_2.c moves_3.c checkerparse.c checker_util.c checker_util2.c
SRC2 = push_swap.c push_swap2.c ps_various.c ps_solve.c ps_moves1.c ps_moves2.c ps_medi.c
SRCC = $(addprefix ./srcs/, $(SRC))
SRCP = $(addprefix ./srcs/, $(SRC2))

all: $(NAME) $(NAME2)

$(NAME): $(SRCC)
	$(MAKE) -C include/libftprintf
	@gcc -o $(NAME) $(FLAG) $(SRCC) include/libftprintf/libftprintf.a
	@echo "\033[32m[✓] \033[33m checker was created successfully"

$(NAME2): $(SRCP)
	@gcc -o $(NAME2) $(FLAG) $(SRCP) include/libftprintf/libftprintf.a
	@echo "\033[32m[✓] \033[33m push_swap was created successfully"

clean:
	$(MAKE) -C include/libftprintf/ clean
	@echo "\033[32m[✓] \033[33m all the object files were DESTROYED"

fclean: clean
	@rm -rf $(NAME) $(NAME2)
	$(MAKE) -C include/libftprintf/ fclean
	@echo "\033[32m[✓] \033[33m checker and push_wap were DESTROYED"

re: fclean all

