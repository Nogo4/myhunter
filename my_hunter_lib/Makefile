##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile for my_hunter project
##

SRC = src/script_game_loop_base.c \
	  src/create_sprite_and_window.c \
	  src/create_hud_player.c \
	  src/draw_sprites.c \
	  src/manage_life.c \
	  src/check_duck_pos.c \
	  src/manage_score.c \
	  src/script_duck_shot.c \
	  src/set_main_data.c \
	  src/my_strcpr.c \

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
