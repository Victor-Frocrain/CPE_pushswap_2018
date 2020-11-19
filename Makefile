##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c		\
		src/my_pushswap.c	\
		src/fill_lists.c	\
		src/sort_s.c		\
		src/sort_p.c		\
		src/sort_r.c		\
		src/sort_rr.c		\
		src/my_arrlen.c		\
		src/check_cases.c	\

OBJ	=	$(SRC:%.c=%.o)

CFLAGS	=	-Wshadow -I ./include

LIB	=	lib/my -lmy

NAME	=	push_swap

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my/
		$(CC) -o $(NAME) $(OBJ) -L $(LIB)

clean:
	make -C lib/my clean
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean:	clean
	make -C lib/my fclean
	rm -f $(NAME)

re:	fclean all
