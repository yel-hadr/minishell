NAME	=	minishell
CC	=	gcc
CFLAGS	=	-Werror -Wextra -Wall -O3 #-g -fsanitize=address



SRCS	=	main.c 

OBJS	=	$(SRCS:.c=.o)

$(NAME): $(OBJS)
	@printf "\033[1;36m Compiling \033[0m LIBFT \033[1;36m√\033[0m\n"
	@$(MAKE) -s all -C ./libft
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Compiling \033[0m PARSER \033[1;36m√\033[0m\n"
	@$(MAKE) -s all -C ./parcing
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Compiling \033[0m EXECUTION \033[1;36m√\033[0m\n"
	@$(MAKE) -s all -C ./execute_unit
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Compiling \033[0m $(NAME) \033[1;36m√\033[0m\n"
	@$(CC) $(CFLAGS) $(OBJS) ./parcing/parser.a ./execute_unit/execute.a ./libft/libft.a -lreadline -o $(NAME)
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[1;36m Compiling \033[0m $< \033[1;36m√\033[0m\n"

all: $(NAME)

clean:
	@printf "\033[1;36m Deleting \033[0m libft OBJ \033[1;36m√\033[0m\n"
	@$(MAKE) -s clean -C ./libft
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Deleting \033[0m PARSER OBJ \033[1;36m√\033[0m\n"
	@$(MAKE) -s clean -C ./parcing
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Deleting \033[0m EXECUTION OBJ\033[1;36m√\033[0m\n"
	@$(MAKE) -s clean -C ./execute_unit
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Deleting \033[0m minishell OBJ \033[1;36m√\033[0m\n"
	@rm -rf $(OBJS)
	@printf "\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

fclean: clean
	@printf "\033[1;36m Deleting \033[0m LIBFT \033[1;36m√\033[0m\n"
	@$(MAKE) -s fclean -C ./libft
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Deleting \033[0m PARSER \033[1;36m√\033[0m\n"
	@$(MAKE) -s fclean -C ./parcing
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Deleting \033[0m EXECUTION \033[1;36m√\033[0m\n"
	@$(MAKE) -s fclean -C ./execute_unit
	@printf "\n\033[1;36m ───────────── Done ──────────── \033[0m\n\n"
	@printf "\033[1;36m Deleting \033[0m $(NAME) \033[1;36m√\033[0m\n"
	@rm -rf $(NAME)
	@printf "\033[1;36m ───────────── Done ──────────── \033[0m\n\n"

re: fclean all
