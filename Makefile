##
## EPITECH PROJECT, 2019
## my_defender
## File description:
## Makefile
##

SRC     =	$(shell find $(SOURCEDIR) -name '*.c')

OBJ     =       $(SRC:.c=.o)

CC	=	gcc $(CSFML_FLAG) -I./include

NAME    =       my_defender

CSFML_FLAG	=	-l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system

C_FLAG	= 	-W -Wall  -Werror -Wextra -pedantic -I include -g3

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(shell find $(SOURCEDIR) -name '*.o')
	rm -f $(shell find $(SOURCEDIR) -name '*~')
	rm -f $(shell find $(SOURCEDIR) -name '*vg*')

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re


