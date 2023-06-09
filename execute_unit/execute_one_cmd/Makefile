NAME = execute_one_cmd.a
DEPS = execute_one_cmd.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = execute_the_cmd.c check_the_cmd.c


OBJ = $(SRC:.c=.o)

all : $(NAME)


$(NAME) : $(OBJ)
	ar rcs $(NAME) $^

clean :
	rm -f *.o

fclean :
	rm -rf *.o *.a

re : fclean all

