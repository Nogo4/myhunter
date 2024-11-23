##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_hunter project
##

SRC =  

OBJ = $(SRC:.c=.o)

NAME = my_hunter_lib.a

CFLAGS += -Wall -Wextra -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc my_hunter_lib.a $(OBJ)

clean:
	rm -f ${OBJ}

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)
