NAME = execute_one_cmd.a
DEPS = execute_one_cmd.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
UTILE = ../libft/libft.a
SRC = execute_the_cmd.c check_the_cmd.c ft_pipe.c ft_redaraction.c\
		ft_error.c ft_strjoin_free.c


OBJ = $(SRC:.c=.o)

all : $(NAME)
	cc -lreadline -o ft_pipe ft_pipe.c $(NAME) $(UTILE)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $^
	make -C ../libft bonus

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C ../libft clean

fclean : clean
	rm -rf $(NAME)
	make -C ../libft fclean

re : fclean all

