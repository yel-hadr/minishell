NAME	=	minishell
CC	=	cc
CFLAGS	=	-Werror -Wextra -Wall -O3  #-g -fsanitize=address

UTILS	=	minishell_utils.a

EXECUTION_SRCS	=	execute_unit/execute_the_cmd.c execute_unit/check_the_cmd.c execute_unit/ft_redaraction.c\
		execute_unit/ft_error.c execute_unit/ft_strjoin_free.c execute_unit/ft_dupenvp.c execute_unit/ft_is_builting.c execute_unit/ft_pipe.c \
		execute_unit/ft_signal.c

PARCING_SRCS	=	parcing/split_cmd.c parcing/struct_cmd.c parcing/split_args.c\
					parcing/parser.c parcing/remove_quotes.c parcing/checker.c\

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
					libft/ft_lstiter_bonus.c libft/ft_lstmap_bonus.c

BUILTING_SRCS	=	 builting/ft_pwd.c builting/ft_exit.c builting/ft_export.c builting/ft_echo.c builting/ft_cd.c builting/ft_env.c builting/ft_unset.c

SRCS	=	main.c 

EXECUTION_OBJS	=	$(EXECUTION_SRCS:.c=.o)
PARCING_OBJS	=	$(PARCING_SRCS:.c=.o)
LIBFT_OBJS		=	$(LIBFT_SRCS:.c=.o)
BUILTING_OBJS	=	$(BUILTING_SRCS:.c=.o)

OBJS	=	$(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -I ~/.brew/opt/readline/include/  -c $< -o $@
	@printf "\033[0;32mCompilation [OK]\033[0m %s\n" $<

all:	$(NAME)

$(NAME) : utiles $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(UTILS) -lreadline -L ~/.brew/opt/readline/lib/ -o $(NAME)
	@printf "\033[0;32mCompilation [OK]\033[0m %s\n" $(NAME)

utiles : $(PARCING_OBJS) $(LIBFT_OBJS) $(BUILTING_OBJS) $(EXECUTION_OBJS)
	@ar rc $(UTILS) $(EXECUTION_OBJS) $(PARCING_OBJS) $(LIBFT_OBJS) $(BUILTING_OBJS)
	@printf "\033[0;32mCompilation [OK]\033[0m %s\n" $(UTILS)

clean:
	@rm -f $(OBJS) $(EXECUTION_OBJS) $(PARCING_OBJS) $(LIBFT_OBJS) $(BUILTING_OBJS)
	@printf "\033[0;32mDelete [OK]\033[0m OBJS\n" 

fclean : clean
	@rm -f $(NAME) $(UTILS)
	@printf "\033[0;32mDelete [OK]\033[0m EXECUTABEL\n"

re : fclean all

do : all
	./minishell
