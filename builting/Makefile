NAME = builting.a

DEPS = builting.h 

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_pwd.c ft_exit.c ft_export.c ft_echo.c ft_cd.c ft_env.c ft_unset.c

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

