# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmsimang <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/12 15:33:06 by jmsimang          #+#    #+#              #
#    Updated: 2018/07/12 15:33:08 by jmsimang         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

SRC1 = push_swap.c helpers.c instructions.c operations.c utilities.c moves.c \
	helpers1.c
SRC2 = checker.c helpers.c instructions.c operations.c utilities.c moves.c \
	helpers1.c
OBJ1 = $(SRC1:.c=.o)
OBJ2 = $(SRC2:.c=.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra -c
OFLAGS = -Wall -Werror -Wextra
DELFLAG = /bin/rm -f

all: $(NAME1) $(NAME2)

$(NAME1):
		@make -C libft/ fclean && make -C libft/
		@echo " ---> Compiling PUSH_SWAP\n"
		@$(CC) -g $(CFLAGS) $(SRC1)
		@$(CC) -g $(OFLAGS) $(OBJ1) libft/libft.a -o $(NAME1)

$(NAME2):
		@echo " ---> Compiling CHECKER\n"
		@$(CC) -g $(CFLAGS) $(SRC2)
		@$(CC) -g $(OFLAGS) $(OBJ2) libft/libft.a -o $(NAME2)

clean: 
		@echo "\n ---> Cleaning out PUSH_SWAP and CHECKER\n"
		@$(DELFLAG) $(OBJ1) $(OBJ2)
		@make -C libft/ clean

fclean: clean
		@echo " ---> Removing PUSH_SWAP and CHECKER\n"
		@$(DELFLAG) $(NAME1) $(NAME2)
		@make -C libft/ fclean

re:		fclean all
