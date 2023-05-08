NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
utile = libft/libft.a
SRC = execute_unit.c
OBJ = $(SRC:.c=.o)

all		: $(NAME)

$(NAME) : utile $(OBJ)
	$(CC) $(CFLAGS) -O3 $(utile) $(OBJ) -o $(NAME)

utile	:
	make -C libft

clean	:
	@rm -f $(OBJ)
	@make -C libft clean

fclean	: clean
	@rm -rf $(NAME)
	@make -C libft fclean 

re		: fclean all