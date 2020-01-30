##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC =	display_window.c \
		event.c \
		move.c \
		music.c \
		my_putchar.c \
		my_putstr.c \
		my_strcmp.c \
		spandtex.c \

OBJ = $(SRC:.c=.o)

NAME = my_hunter

all: $(NAME)

$(NAME):   $(OBJ)
	$(CC) $(OBJ) -o $(NAME) -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all