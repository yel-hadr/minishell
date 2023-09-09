NAME	=	minishell
CC	=	cc
CFLAGS	=	-Werror -Wextra -Wall -O3 #-g -fsanitize=address



SRCS	=	main.c 

OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@printf "\033[1;36m Compiling \033[0m LIBFT \033[1;36m√\033[0m\n"
	@$(MAKE) -s all -C ./libft
	@printf "\033[1;36m Compiling \033[0m PARSER \033[1;36m√\033[0m\n"
	@$(MAKE) -s all -C ./parcing
	@printf "\033[1;36m Compiling \033[0m EXECUTION \033[1;36m√\033[0m\n"
	@$(MAKE) -s all -C ./execute_unit
	@printf "\033[1;36m Compiling \033[0m BUILTING \033[1;36m√\033[0m\n"
	@$(MAKE) -s all -C ./builting
	@printf "\033[1;36m Compiling \033[0m $(NAME) \033[1;36m√\033[0m\n"
	@$(CC) $(CFLAGS) $(OBJS) ./parcing/parser.a ./execute_unit/execute.a builting/builting.a ./libft/libft.a -o $(NAME)
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[1;36m Compiling \033[0m $< \033[1;36m√\033[0m\n"

run: re
	@./$(NAME)

all: $(NAME)

clean:
	@printf "\033[1;36m Deleting \033[0m libft OBJ \033[1;36m√\033[0m\n"
	@$(MAKE) -s fclean -C ./libft
	@printf "\033[1;36m Deleting \033[0m PARSER OBJ \033[1;36m√\033[0m\n"
	@$(MAKE) -s fclean -C ./parcing
	@printf "\033[1;36m Deleting \033[0m EXECUTION OBJ\033[1;36m√\033[0m\n"
	@$(MAKE) -s fclean -C ./execute_unit
	@printf "\033[1;36m Deleting \033[0m BUILTING OBJ\033[1;36m√\033[0m\n"
	@$(MAKE) -s fclean -C ./builting
	@printf "\033[1;36m Deleting \033[0m minishell OBJ \033[1;36m√\033[0m\n"
	@rm -rf $(OBJS)
	@printf "\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

fclean: clean
	@printf "\033[1;36m Deleting \033[0m $(NAME) \033[1;36m√\033[0m\n"
	@rm -rf $(NAME)
	@printf "\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

re: fclean all
