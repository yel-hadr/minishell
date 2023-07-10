NAME = execute.a
DEPS = execute.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
UTILE = ../libft/libft.a builting/builting.a
SRC = execute_the_cmd.c check_the_cmd.c ft_redaraction.c\
		ft_error.c ft_strjoin_free.c ft_dupenvp.c ft_is_builting.c ft_pipe.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $^

%.o : %.c $(DEPS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)


re : fclean all

