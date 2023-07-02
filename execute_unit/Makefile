NAME = execute.a
DEPS = execute.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
UTILE = ../libft/libft.a builting/builting.a
SRC = execute_the_cmd.c check_the_cmd.c ft_pipe.c ft_redaraction.c\
		ft_error.c ft_strjoin_free.c ft_dupenvp.c ft_is_builting.c


OBJ = $(SRC:.c=.o)

all : $(NAME)
	cc -lreadline -o ft_pipe ft_pipe.c $(NAME) $(UTILE)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $^
	make -C ../libft bonus
	make -C builting

%.o : %.c $(DEPS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)
	make -C ../libft clean
	make -C builting clean

fclean : clean
	@rm -rf $(NAME)
	@make -C ../libft fclean
	@make -C builting fclean
re : fclean all

