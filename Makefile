##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

SRC	=	$(wildcard SRC/*.c)

CFLAGS = -W -Wall -Wextra -Wno-deprecated-declarations -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

all:	$(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) -o $(NAME) -g

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re