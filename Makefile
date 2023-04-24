##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## hey
##

SRC =	main.c \
		function.c \
		function2.c \
		error.c	\
		check.c

OBJ = $(SRC:.c=.o)

NAME = mysh

$(NAME): $(OBJ)
	cd lib/my/ && make all
	gcc $(OBJ) -I. -L ./lib/my/ -lmy -Wextra -Wall -o $(NAME) -g

clean:
	rm -f $(OBJ)
	cd lib/my/ && make clean
fclean: clean
	rm -f $(NAME)
	cd lib/my/ && make fclean

re: fclean $(NAME)
