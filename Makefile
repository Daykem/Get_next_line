##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Made by Devlopers
##

SRC_UT	=	get_next_line.c		\
		tests/test.c

CFLAGS	+=	-Wall -Wextra -Iinclude

LDFLAGS	=	-lcriterion -lgcov

NAME_UT	=	unit-tests

OBJ_UT	=	$(SRC_UT:.c=.o)

tests_run:	$(OBJ_UT)
	cc -o $(NAME_UT) $(OBJ_UT) $(LDFLAGS) --coverage
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcna
	rm -f *.gcno
	./unit-tests

clean:
	rm -f $(OBJ_UT)

fclean:	clean
	rm -f $(NAME_UT)
	rm -f unit-tests
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcdo
	rm -f *.gcna
	rm -f *.gcno

re:	fclean all
