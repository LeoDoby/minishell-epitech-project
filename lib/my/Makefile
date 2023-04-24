##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## hey
##

SRC =	my_strupcase.c		\
		my_getnbr.c			\
		my_strdup.c			\
		my_strcmp.c			\
		my_strcpy.c			\
		my_str_isalpha.c			\
		my_strncpy.c			\
		my_intdup.c			\
		my_put_nbr.c			\
		my_sort_int_array.c			\
		my_putchar.c			\
		my_strcat.c			\
		my_showstr.c			\
		my_put_int.c			\
		my_strcapitalize.c			\
		my_strstr.c			\
		my_str_isupper.c			\
		my_strlen.c			\
		my_str_to_word_array.c			\
		my_strncmp.c			\
		my_str_isprintable.c			\
		my_strlowcase.c			\
		my_revstr.c			\
		my_strncat.c			\
		my_str_islower.c			\
		my_octal.c			\
		my_compute_power_rec.c			\
		my_putstr.c			\
		my_swap.c			\
		my_showmem.c			\
		my_show_word_array.c			\
		my_str_isnum.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/
	cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
