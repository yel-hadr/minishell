NAME = builting.a
DEPS = builting.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
UTILE = ../../libft/libft.a ../execute.a
SRC = ft_cd.c ft_echo.c ft_exit.c ft_export.c ft_pwd.c


OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rcs $(NAME) $^

%.o : %.c $(DEPS) ../execute.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

