NAME = execute.a

DEPS = execute.h builting.h 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = execute_the_cmd.c check_the_cmd.c ft_redaraction.c\
		ft_error.c ft_strjoin_free.c ft_dupenvp.c ft_is_builting.c ft_pipe.c \
		ft_pwd.c ft_exit.c ft_export.c ft_echo.c ft_cd.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)


%.o : %.c $(DEPS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

