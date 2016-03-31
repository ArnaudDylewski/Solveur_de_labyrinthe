CC =	gcc
NAME =	solve
SRC =	fonction_base.c 	\
	fonction_base2.c 	\
	fonction_map.c 		\
	fonction_deplace.c	\
	start.c 		\
	main.c		

OBJ = 	$(SRC:%.c=%.o)
CFLAGS = -Werror -W -Wextra -Wall -g
RM =	rm -f

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:			clean
		$(RM) $(NAME)

re:		fclean all