##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_hunter project
##

SRC = main.c

OBJ = $(SRC:.c=.o)

NAME = my_hunter

CFLAGS += -Ilib/include


LIB =	lib/libmy.a \
		my_hunter_lib/my_hunter_lib.a \

CFLAGS += -l csfml-audio
CFLAGS += -l csfml-graphics
CFLAGS += -l csfml-system
CFLAGS += -l csfml-window
CFLAGS += -l csfml-network
CFLAGS += -Wextra
CFLAGS += -Wall
CFLAGS += -fsanitize=address -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib
	make -C my_hunter_lib
	gcc -g3 -o $(NAME) $(OBJ) $(LIB) $(CFLAGS)

clean:
	rm -f $(OBJ)
	make clean -C lib
	make clean -C my_hunter_lib

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)

lib_clean:
	make clean -C lib
	make clean -C my_hunter_lib
