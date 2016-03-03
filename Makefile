##
## Makefile for BSQ in /home/Speedy/Work/CPE_2015_BSQ
##
## Made by Clemenceau Cédric
## Login   <Speedy@epitech.net>
##
## Started on  Tue Dec  8 13:20:01 2015 Clemenceau Cédric
## Last update Sun Feb 21 18:06:43 2016 Clémenceau Cedric
##

CC	=	gcc -g

RM	=	rm -f

CFLAGS	=	-I./include
CFLAGS	+=	-Wall -W -Wextra -ansi -pedantic

SRC	=	src/allum1.c \
		src/get_next_line.c \
		src/my_getnbr.c \
		src/put_nbrs.c \
		src/aff_alum.c \
		src/error_alum.c \
		src/calcul_alum.c \
		src/ai_alum.c

OBJ	=	$(SRC:.c=.o)

NAME	=	allum1

$(NAME)	:	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
