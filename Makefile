NAME	=	minishell
CC	=	cc
CFLAGS	=	-g #-Werror -Wextra -Wall -O3  #-g -fsanitize=address

UTILS	=	minishell_utils.a

EXECUTION_SRCS	=	execute_unit/ft_execute.c execute_unit/ft_search_path.c execute_unit/ft_redirection.c\
					execute_unit/ft_dupenvp.c execute_unit/ft_is_builting.c execute_unit/ft_pipe.c\
					execute_unit/ft_signal.c

PARSING_SRCS	=	parsing/split_cmd.c parsing/struct_cmd.c parsing/split_args.c\
					parsing/parser.c parsing/remove_quotes.c parsing/checker.c\
					parsing/get_redir.c parsing/expand_variable.c parsing/ft_get_herdoc.c\
					parsing/wildcards.c\

LIBFT_SRCS		=	libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c\
					libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_strlen.c libft/ft_memcpy.c\
					libft/ft_strdup.c libft/ft_toupper.c libft/ft_bzero.c libft/ft_memchr.c libft/ft_memmove.c libft/ft_strlcat.c\
					libft/ft_strrchr.c libft/ft_memcmp.c libft/ft_memset.c libft/ft_strlcpy.c libft/ft_tolower.c libft/ft_strchr.c\
					libft/ft_atoi.c libft/ft_strtrim.c libft/ft_strnstr.c libft/ft_substr.c libft/ft_calloc.c libft/ft_strjoin.c\
					libft/ft_split.c libft/ft_itoa.c libft/ft_putnbr_fd.c libft/ft_striteri.c libft/ft_strncmp.c libft/ft_strmapi.c\
					libft/ft_strcmp.c libft/ft_strndup.c libft/wd_replace.c libft/all_wrds_replace.c libft/ft_strcpy.c\
					libft/all_wrds_replace.c libft/ft_isspace.c libft/ft_strnew.c libft/ft_lstnew_bonus.c\
					libft/ft_lstadd_front_bonus.c libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c\
					libft/ft_lstadd_back_bonus.c libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c\
					libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c libft/ft_error.c libft/ft_strjoin_free.c\

BUILTING_SRCS	=	builting/ft_pwd.c builting/ft_exit.c builting/ft_export.c builting/ft_echo.c builting/ft_cd.c\
					builting/ft_env.c builting/ft_unset.c

SRCS	=	main.c 

EXECUTION_OBJS	=	$(EXECUTION_SRCS:.c=.o)
PARSING_OBJS	=	$(PARSING_SRCS:.c=.o)
LIBFT_OBJS		=	$(LIBFT_SRCS:.c=.o)
BUILTING_OBJS	=	$(BUILTING_SRCS:.c=.o)

OBJS	=	$(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32mCompilation [OK]\033[0m %s\n" $<

all:	$(NAME)

$(NAME) : $(PARSING_OBJS) $(LIBFT_OBJS) $(BUILTING_OBJS) $(EXECUTION_OBJS) $(OBJS)
	@ar rc $(UTILS) $(EXECUTION_OBJS) $(PARSING_OBJS) $(LIBFT_OBJS) $(BUILTING_OBJS)
	@printf "\033[0;32mCompilation [OK]\033[0m %s\n" $(UTILS)
	@$(CC) $(CFLAGS) $(OBJS) $(UTILS) -lreadline -o $(NAME)
	@printf "\033[0;32mCompilation [OK]\033[0m %s\n" $(NAME)


clean:
	@rm -f $(OBJS)
	@printf "\033[0;32mDelete [OK]\033[0m OBJECTS\n"
	@rm -f $(EXECUTION_OBJS)
	@printf "\033[0;32mDelete [OK]\033[0m EXECUTION_OBJS\n"
	@rm -f $(PARSING_OBJS)
	@printf "\033[0;32mDelete [OK]\033[0m PARSING_OBJS\n"
	@rm -f $(LIBFT_OBJS)
	@printf "\033[0;32mDelete [OK]\033[0m LIBFT_OBJS\n"
	@rm -f $(BUILTING_OBJS)
	@printf "\033[0;32mDelete [OK]\033[0m BUILTING_OBJS\n"
	@rm -f $(UTILS)
	@printf "\033[0;32mDelete [OK]\033[0m UTILS\n"

fclean : clean
	@rm -f $(NAME)
	@printf "\033[0;32mDelete [OK]\033[0m %s\n" $(NAME)

re : fclean all

do : all
	./minishell
